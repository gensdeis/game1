#include "stdafx_net.h"
#include "AuthCrypt.h"
#include "HMACSHA1.h"
#include "BigNumber.h"

AuthCrypt::AuthCrypt() : _clientDecrypt(SHA_DIGEST_LENGTH), _serverEncrypt(SHA_DIGEST_LENGTH)
{
	_initialized = false;
}

AuthCrypt::~AuthCrypt()
{
}

void AuthCrypt::Init(BigNumber* K)
{
	uint8_t ServerEncryptionKey[SEED_KEY_SIZE] = { 0x4f, 0x18, 0x5b, 0x4f, 0x65, 0x39, 0xc9, 0x18, 0x1d, 0x5e, 0xe2, 0xf3, 0xd8, 0xa9, 0x47, 0x53 };

	HMACSHA1 serverEncryptHmac(SEED_KEY_SIZE, (uint8_t*)ServerEncryptionKey);
	uint8_t* encryptHash = serverEncryptHmac.ComputeHash(K);

	uint8_t ServerDecryptionKey[SEED_KEY_SIZE] = { 0x5b, 0x66, 0x52, 0x3b, 0x93, 0xae, 0x88, 0xec, 0x88, 0x43, 0x53, 0x85, 0x6d, 0x85, 0x4d, 0xc9 };

	HMACSHA1 clientDecryptHmac(SEED_KEY_SIZE, (uint8_t*)ServerDecryptionKey);
	uint8_t* decryptHash = clientDecryptHmac.ComputeHash(K);

	// ARC4 _serverDecrypt(encryptHash);
	_clientDecrypt.Init(decryptHash);
	_serverEncrypt.Init(encryptHash);
	//ARC4 _clientEncrypt(SHA_DIGEST_LENGTH);
	//_clientEncrypt.Init(decryptHash);

	uint8_t syncBuf[1024];

	memset(syncBuf, 0, 1024);

	_serverEncrypt.UpdateData(1024, syncBuf);
	//_clientEncrypt.UpdateData(1024, syncBuf);

	memset(syncBuf, 0, 1024);

	//_serverDecrypt.UpdateData(1024, syncBuf);
	_clientDecrypt.UpdateData(1024, syncBuf);

	_initialized = true;
}

void AuthCrypt::DecryptRecv(uint8_t* data, size_t len)
{
	if (!_initialized)
	{
		return;
	}

	_clientDecrypt.UpdateData(static_cast<int32_t>(len), data);
}

void AuthCrypt::EncryptSend(uint8_t* data, size_t len)
{
	if (!_initialized)
	{
		return;
	}

	_serverEncrypt.UpdateData(static_cast<int32_t>(len), data);
}

void AuthCrypt::ReleaseCrypt()
{
	_initialized = false;
}


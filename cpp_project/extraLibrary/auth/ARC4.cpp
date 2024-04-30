#include "stdafx_net.h"
#include "ARC4.h"

ARC4::ARC4(uint8_t len) : m_ctx()
{
    m_ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(m_ctx, EVP_rc4(), NULL, NULL, NULL);
    EVP_CIPHER_CTX_set_key_length(m_ctx, len);
}

ARC4::ARC4(uint8_t* seed, uint8_t len) : m_ctx()
{
    m_ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(m_ctx, EVP_rc4(), NULL, NULL, NULL);
    EVP_CIPHER_CTX_set_key_length(m_ctx, len);
    EVP_EncryptInit_ex(m_ctx, NULL, NULL, seed, NULL);
}

ARC4::~ARC4()
{
    EVP_CIPHER_CTX_free(m_ctx);
}

void ARC4::Init(uint8_t* seed)
{
    EVP_EncryptInit_ex(m_ctx, NULL, NULL, seed, NULL);
}

void ARC4::UpdateData(int len, uint8_t* data)
{
    int outlen = 0;
    EVP_EncryptUpdate(m_ctx, data, &outlen, data, len);
    EVP_EncryptFinal_ex(m_ctx, data, &outlen);
}

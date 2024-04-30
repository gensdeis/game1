#pragma once

#include <common/util.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

class BigNumber;

#define SEED_KEY_SIZE 16

class HMACSHA1
{
public:
    HMACSHA1(uint32_t len, uint8_t* seed);
    ~HMACSHA1();

    void UpdateBigNumber(BigNumber* bn);
    void UpdateData(const uint8_t* data, int length);
    void UpdateData(const std::string& str);
    void Finalize();

    uint8_t* ComputeHash(BigNumber* bn);
    uint8_t* GetDigest() { return (uint8_t*)m_digest; }
    int GetLength() { return SHA_DIGEST_LENGTH; }

private:

#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_CTX m_ctx;
#else
    HMAC_CTX* m_ctx;
#endif

    uint8_t m_digest[SHA_DIGEST_LENGTH];
};
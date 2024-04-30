#include "stdafx_net.h"
#include "HMACSHA1.h"
#include "BigNumber.h"

HMACSHA1::HMACSHA1(uint32_t len, uint8_t* seed)
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_CTX_init(&m_ctx);
    HMAC_Init_ex(&m_ctx, seed, len, EVP_sha1(), NULL);
#else
    m_ctx = HMAC_CTX_new();
    HMAC_Init_ex(m_ctx, seed, len, EVP_sha1(), NULL);
#endif
}

HMACSHA1::~HMACSHA1()
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_CTX_cleanup(&m_ctx);
#else
    HMAC_CTX_free(m_ctx);
#endif
}

void HMACSHA1::UpdateBigNumber(BigNumber* bn)
{
    UpdateData(bn->AsByteArray(), bn->GetNumBytes());
}

void HMACSHA1::UpdateData(const uint8_t* data, int length)
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_Update(&m_ctx, data, length);
#else
    HMAC_Update(m_ctx, data, length);
#endif
}

void HMACSHA1::UpdateData(const std::string& str)
{
    UpdateData((uint8_t const*)str.c_str(), static_cast<int32_t>(str.length()));
}

void HMACSHA1::Finalize()
{
    uint32_t length = 0;
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_Final(&m_ctx, (uint8_t*)m_digest, &length);
#else
    HMAC_Final(m_ctx, (uint8_t*)m_digest, &length);
#endif
}

uint8_t* HMACSHA1::ComputeHash(BigNumber* bn)
{
#if OPENSSL_VERSION_NUMBER < 0x10100000L
    HMAC_Update(&m_ctx, bn->AsByteArray(), bn->GetNumBytes());
#else
    HMAC_Update(m_ctx, bn->AsByteArray(), bn->GetNumBytes());
#endif
    Finalize();
    return (uint8_t*)m_digest;
}

#pragma once

#include <common/util.h>
#include <openssl/evp.h>

class ARC4
{
public:
    ARC4(uint8_t len);
    ARC4(uint8_t* seed, uint8_t len);
    ~ARC4();

    void Init(uint8_t* seed);
    void UpdateData(int len, uint8_t* data);

private:
    EVP_CIPHER_CTX* m_ctx;
};
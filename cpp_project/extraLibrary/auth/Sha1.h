#pragma once

#include <common/util.h>
#include <openssl/sha.h>
#include <openssl/crypto.h>

class BigNumber;

class Sha1Hash
{
public:
    Sha1Hash();
    ~Sha1Hash();

    void UpdateBigNumbers(BigNumber* bn0, ...);

    void UpdateData(const uint8_t* dta, int len);
    void UpdateData(const std::string& str);

    void Initialize();
    void Finalize();

    uint8_t* GetDigest(void) { return mDigest; };
    int GetLength(void) { return SHA_DIGEST_LENGTH; };

private:
    SHA_CTX mC;
    uint8_t mDigest[SHA_DIGEST_LENGTH];
};
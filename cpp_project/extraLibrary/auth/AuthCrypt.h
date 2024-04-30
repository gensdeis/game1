#pragma once
#include <common/util.h>

#include "ARC4.h"

class BigNumber;

class AuthCrypt
{
public:
    AuthCrypt();
    ~AuthCrypt();

    void Init(BigNumber* K);
    void DecryptRecv(uint8_t*, size_t);
    void EncryptSend(uint8_t*, size_t);
    void ReleaseCrypt();

    bool IsInitialized() { return _initialized; }

private:
    ARC4 _clientDecrypt;
    ARC4 _serverEncrypt;
    bool _initialized;
};
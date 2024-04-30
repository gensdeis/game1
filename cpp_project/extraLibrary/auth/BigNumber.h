#pragma once

#include <common/util.h>

struct bignum_st;

class BigNumber
{
public:

    BigNumber();
    BigNumber(const BigNumber& bn);
    BigNumber(uint32_t);
    ~BigNumber();

    void SetDword(uint32_t);
    void SetQword(uint64_t);
    void SetBinary(const uint8_t* bytes, int len);
    void SetHexStr(const char* str);

    void SetRand(int numbits);

    BigNumber operator=(const BigNumber& bn);
    BigNumber operator+=(const BigNumber& bn);
    BigNumber operator+(const BigNumber& bn)
    {
        BigNumber t(*this);
        return t += bn;
    }
    BigNumber operator-=(const BigNumber& bn);
    BigNumber operator-(const BigNumber& bn)
    {
        BigNumber t(*this);
        return t -= bn;
    }
    BigNumber operator*=(const BigNumber& bn);
    BigNumber operator*(const BigNumber& bn)
    {
        BigNumber t(*this);
        return t *= bn;
    }
    BigNumber operator/=(const BigNumber& bn);
    BigNumber operator/(const BigNumber& bn)
    {
        BigNumber t(*this);
        return t /= bn;
    }
    BigNumber operator%=(const BigNumber& bn);
    BigNumber operator%(const BigNumber& bn)
    {
        BigNumber t(*this);
        return t %= bn;
    }

    bool isZero() const;

    BigNumber ModExp(const BigNumber& bn1, const BigNumber& bn2);
    BigNumber Exp(const BigNumber&);

    int GetNumBytes(void);

    struct bignum_st* BN() { return _bn; }

    uint32_t AsDword();
    uint8_t* AsByteArray(int minSize = 0);
    uint8_t* AsByteArray(int minSize, bool reverse);
    const char* AsHexStr();
    const char* AsDecStr();

private:
    struct bignum_st* _bn;
    uint8_t* _array;
};
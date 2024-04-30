#include "stdafx_net.h"
#include "Sha1.h"
#include "BigNumber.h"

Sha1Hash::Sha1Hash()
{
    SHA1_Init(&mC);
}

Sha1Hash::~Sha1Hash()
{
    SHA1_Init(&mC);
}

void Sha1Hash::UpdateData(const uint8_t* dta, int len)
{
    SHA1_Update(&mC, dta, len);
}

void Sha1Hash::UpdateData(const std::string& str)
{
    UpdateData((uint8_t const*)str.c_str(), static_cast<int32_t>(str.length()));
}

void Sha1Hash::UpdateBigNumbers(BigNumber* bn0, ...)
{
    va_list v;
    BigNumber* bn;

    va_start(v, bn0);
    bn = bn0;
    while (bn)
    {
        UpdateData(bn->AsByteArray(), bn->GetNumBytes());
        bn = va_arg(v, BigNumber*);
    }
    va_end(v);
}

void Sha1Hash::Initialize()
{
    SHA1_Init(&mC);
}

void Sha1Hash::Finalize(void)
{
    SHA1_Final(mDigest, &mC);
}

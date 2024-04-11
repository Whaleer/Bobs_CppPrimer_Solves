//
// Created by Bingxi L on 2024/4/11.
//
#include "12_19.h"

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}
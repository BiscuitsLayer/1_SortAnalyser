#include "logint.hpp"

LogInt::LogInt (int data):
    data_ (data),
    cmpCnt_ (0),
    swapCnt_ (0)
    {}

std::pair <size_t, size_t> LogInt::GetCounter () const {
    return std::make_pair (cmpCnt_, swapCnt_);
}

void LogInt::CmpInc () const {
    ++cmpCnt_;
}

void LogInt::SwapInc () const {
    ++swapCnt_;
} 

bool operator < (const LogInt& lhs, const LogInt& rhs) {
    lhs.CmpInc ();
    rhs.CmpInc ();
    return lhs.data_ < rhs.data_;
}

bool operator <= (const LogInt& lhs, const LogInt& rhs) {
    lhs.CmpInc ();
    rhs.CmpInc ();
    return lhs.data_ <= rhs.data_;
}

void swap (LogInt* lhs, LogInt* rhs) {
    LogInt temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
    lhs->SwapInc ();
    rhs->SwapInc ();
}
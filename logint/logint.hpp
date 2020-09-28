#ifndef LOGINT_HPP
#define LOGINT_HPP

#include <iostream>
#include <utility>

class LogInt {
    public:
        int data_ = 0;
        LogInt () = default;
        LogInt (int data);
        std::pair <size_t, size_t> GetCounter () const;
        void CmpInc () const;       //  const чтобы можно было вызвать в операторе +
        void SwapInc () const; 
    private:
        mutable size_t cmpCnt_ = 0; //  mutable поскольку её изменение никак не повлияет на объект
        mutable size_t swapCnt_ = 0;
};

bool operator < (const LogInt& lhs, const LogInt& rhs);
bool operator <= (const LogInt& lhs, const LogInt& rhs);
void swap (LogInt* lhs, LogInt* rhs);

#endif //LOGINT_HPP
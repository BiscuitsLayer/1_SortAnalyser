#ifndef SORTS_HPP
#define SORTS_HPP

#include "../logint/logint.hpp"

namespace sorts {
    void QuickSort (LogInt* begin, LogInt* end);
    void Merge (LogInt* left, LogInt* middle, LogInt* right);
    void MergeSort (LogInt* begin, LogInt* end);
    void BubbleSort (LogInt* begin, LogInt* end);
    void SelectionSort (LogInt* begin, LogInt* end);
    void BogoSort (LogInt* begin, LogInt* end);
}

#endif //SORTS_HPP
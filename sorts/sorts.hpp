#ifndef SORTS_HPP
#define SORTS_HPP

#include "../logint/logint.hpp"

class SortType {
public:
    SortType ();
    SortType (std::string name, void (*sortFunction)(LogInt* begin, LogInt* end));
private:
    std::string name_ = {};
    void (*sortFunction_)(LogInt* begin, LogInt* end);
};

namespace sorts {
    void QuickSort (LogInt* begin, LogInt* end);
    void MergeSort (LogInt* begin, LogInt* end);
    void BubbleSort (LogInt* begin, LogInt* end);
    void SelectionSort (LogInt* begin, LogInt* end);
    void BogoSort (LogInt* begin, LogInt* end);
}

#endif //SORTS_HPP
#include "sorts.hpp"

void sorts::QuickSort (LogInt* begin, LogInt* end) {
    LogInt* left = begin;
    LogInt* right = end;
    LogInt* middle = begin + (end - begin) / 2;
    while (left <= right) {
        while (*left < *middle)
            ++left;
        while (*middle < *right)
            --right;
        if (left <= right) {
            if (*right < *left )
                swap (left, right);
            ++left;
            if (begin < right)
                --right;
        }
    }
    if (begin < right)
        QuickSort (begin, right);
    if (left < end)
        QuickSort (left, end);
}

void sorts::Merge (LogInt* left, LogInt* middle, LogInt* right) {
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    
    //  TEMP ARRAYS //
    LogInt *leftPart = new LogInt [leftSize];
    LogInt *rightPart = new LogInt [rightSize];
    LogInt *ans = left;
  
    //  COPY DATA   //
    for (int i = 0; i < leftSize; i++) 
        leftPart[i] = left[i];
    for (int j = 0; j < rightSize; j++)
        rightPart[j] = middle[j + 1];
  
    //     MERGE    //
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) { 
        if (leftPart[i] <= rightPart[j]) {
            ans[k] = leftPart[i];
            ++i;
        } 
        else { 
            ans[k] = rightPart[j];
            ++j;
        } 
        ++k; 
    } 
    
    //  REST OF DATA  //
    while (i < leftSize) { 
        ans[k] = leftPart[i];
        ++i, ++k;
    } 
    while (j < rightSize) { 
        ans[k] = rightPart[j];
        ++j, ++k; 
    } 
} 

void sorts::MergeSort (LogInt* begin, LogInt* end) { 
    if (begin < end) {
        LogInt* middle = begin + (end - begin) / 2; 
        MergeSort (begin, middle); 
        MergeSort (middle + 1, end); 
        Merge (begin, middle, end); 
    } 
} 

void sorts::BubbleSort (LogInt* begin, LogInt* end) {
    size_t iters = -1;
    while (iters != 0) {
        iters = 0;
        for (LogInt* i = begin; i != end; ++i) {
            if (*(i + 1) < *i) {
                swap (i, i + 1);
                ++iters;
            }
        }
    }
}

void sorts::SelectionSort (LogInt* begin, LogInt* end) {
    for (LogInt* i = begin; i != end + 1; ++i) {
        LogInt* curMin = i;
        for (LogInt* j = i; j != end + 1; ++j) {
            if (*j < *curMin) {
                curMin = j;
            }
        }
        swap (i, curMin);
    }
}

void sorts::BogoSort (LogInt* begin, LogInt* end) {
    for (LogInt* i = begin; i != end; ++i) {
        if (*(i + 1) < *i) {
            i = begin;
            //  SHUFFLE  //
            for (LogInt* j = begin; j != end; ++j) {
                swap (j, begin + rand () % (end - begin + 1));
            }
        }
    }
}
#ifndef CQSORT_TPP
#define CQSORT_TPP
#include "cqsort.hpp"

template <typename T>
void swap(T* a, T* b)
{
    auto t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
void CQSort<T>::quicksort(T &vec, int low, int high)
{
    if (low < high)
    {
       auto pivot = vec[high]; 
        int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++; 
            swap(&vec[i], &vec[j]);
        }
    }
    swap(&vec[i + 1], &vec[high]);

        auto pi = i + 1;

        if (th_has_cre < th_to_cre && th_to_cre != 0)
        {
            auto combo = [&]()
            { quicksort(vec, low, pi - 1); };
            std::async(combo);
            th_has_cre++;
            if (th_has_cre < th_to_cre)
            {
                auto combo2 = [&]()
                { quicksort(vec, pi + 1, high); };
                std::async(combo2);
                th_has_cre++;
            }
            else
            {
                quicksort(vec, pi + 1, high);
            }
        }
        else
        {
            quicksort(vec, low, pi - 1);
            quicksort(vec, pi + 1, high);
        }
    }
}

#endif

#ifndef CQSORT_HPP
#define CQSORT_HPP
#include <algorithm>
#include <thread>
#include <future>
#include <atomic>
#include <iostream>
#include <vector>

template <typename T>
class CQSort
{
private:
	int th_to_cre;
	int th_has_cre;
	void quicksort(T &vec, int low, int high);
public:
	CQSort(int mthr)
	{
		int N = std::thread::hardware_concurrency() - 1;
		if (mthr > N)
		{
			th_to_cre = N;
		}
		else
		{
			th_to_cre = mthr;
		}
		th_has_cre = 0;
	}

	void operator()(T &vec)
	{
		int size = vec.size();
		quicksort(vec, 0, size - 1);
		// 		std::cout << th_to_cre << "threads required" << std::endl;

		//std::cout << th_has_cre << "threads used" << std::endl;

	}
};

#include "cqsort.tpp"
#endif // CQSORT_HPP

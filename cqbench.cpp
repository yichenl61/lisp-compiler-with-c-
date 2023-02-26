#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <tuple>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "cqsort.hpp"
template <typename T>
bool is_sorted(const T &vec)
{
	for (auto i = 1; i < vec.size(); ++i)
	{
		if (vec[i - 1] > vec[i])
		{
			return false;
		}
	}
	return true;
}

std::vector<double> benmarklist(std::vector<int> list)
{
	std::vector<double> seq;
	std::vector<double> con;
	int constexpr round = 10;
	for (int i = 0; i < round; ++i)
	{
		int constexpr max_number = 10000000;
		srand((unsigned)time(NULL));
		std::generate(list.begin(), list.end(), []()
					  { return std::rand() % max_number; });
		std::vector<int> temp_seq = list;
		std::vector<int> temp_con = list;
		std::chrono::time_point<std::chrono::system_clock> start_seq;
		std::chrono::time_point<std::chrono::system_clock> end_seq;
		std::chrono::time_point<std::chrono::system_clock> start_con;
		std::chrono::time_point<std::chrono::system_clock> end_con;
		std::chrono::duration<double> elapsed_seconds_seq;
		//////////seq time///////
		CQSort<std::vector<int>> cqsort(0);
		start_seq = std::chrono::system_clock::now();
		cqsort(temp_seq);
		end_seq = std::chrono::system_clock::now();
		if (!is_sorted(temp_seq))
		{
			std::cout << "error" << std::endl;
		}
		elapsed_seconds_seq = end_seq - start_seq;
		seq.push_back(elapsed_seconds_seq.count());
		/////////con time/////////
		std::chrono::duration<double> elapsed_seconds_con;
		start_con = std::chrono::system_clock::now();
		CQSort<std::vector<int>> cqsort1(6);
		cqsort1(temp_con);
		end_con = std::chrono::system_clock::now();
		if (!is_sorted(temp_con))
		{
			std::cout << "con not error" << std::endl;
		}
		elapsed_seconds_con = end_con - start_con;
		con.push_back(elapsed_seconds_con.count());
	}
	double max_seq = *std::max_element(std::begin(seq), std::end(seq));
	double min_seq = *std::min_element(std::begin(seq), std::end(seq));
	double average_seq = std::accumulate(seq.begin(), seq.end(), 0.0) / seq.size();
	double max_con = *std::max_element(std::begin(con), std::end(con));
	double min_con = *std::min_element(std::begin(con), std::end(con));
	double average_con = std::accumulate(con.begin(), con.end(), 0.0) / con.size();
	int int_length = std::to_string(list.size()).length();
	int constexpr small_coloum = 8;
	int constexpr large_coloum = 11;
	std::cout.precision(2);
	std::cout << std::setw(large_coloum) << std::left << list.size()
			  << std::setw(small_coloum) << std::left << min_seq << std::setw(small_coloum) << std::left << max_seq << std::setw(large_coloum) << std::left << average_seq
			  << std::setw(small_coloum) << std::left << min_con << std::setw(small_coloum) << std::left << max_con << std::setw(small_coloum) << std::left << average_con << std::endl;
	std::vector<double> vec;
	vec.push_back(min_seq);
	vec.push_back(max_seq);
	vec.push_back(average_seq);
	vec.push_back(min_con);
	vec.push_back(max_con);
	vec.push_back(average_con);
	return vec;
}

int main(int argc, char *argv[])
{
	int N = std::thread::hardware_concurrency();
	std::vector<std::vector<int>> the_list;
	int constexpr num_of_list = 7;
	int constexpr power_base = 10;
	for (int i = 0; i < num_of_list; i++)
	{
		std::vector<int> temp(pow(power_base,i));
		the_list.push_back(temp);
	}
	std::cout << "List Size   Sequential Sort Time (s)   Concurrent Sort Time (s)" << std::endl;
	std::cout << "             min     max    average     min     max    average" << std::endl;
	std::cout << "---------   -----   -----   -------    -----   -----   -------" << std::endl;

	std::ofstream myfile;
	myfile.open("benchmark.txt");
	myfile << "List Size   Sequential Sort Time (s)   Concurrent Sort Time (s)\n";
	myfile << "             min     max    average     min     max    average\n";
	myfile << "---------   -----   -----   -------    -----   -----   -------\n";

	for (int i = 0; i < num_of_list; i++)
	{
		int constexpr small_coloum = 8;
		int constexpr large_coloum = 11;
		std::vector<double> temp;
		temp = benmarklist(the_list[i]);
		myfile.precision(2);
		myfile << std::setw(large_coloum) << std::left << the_list[i].size()
			   << std::setw(small_coloum) << std::left << temp[0]
			   << std::setw(small_coloum) << std::left << temp[1]
			   << std::setw(large_coloum) << std::left << temp[2]
			   << std::setw(small_coloum) << std::left << temp[3]
			   << std::setw(small_coloum) << std::left << temp[4]
			   << std::setw(small_coloum) << std::left << temp[4 + 1] << "\n";
	}
	myfile.close();
}
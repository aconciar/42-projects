/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:24:03 by andrea            #+#    #+#             */
/*   Updated: 2024/11/07 16:27:52 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

int	Jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}

void printTime(struct timeval start, struct timeval end, size_t size, const std::string& container)
{
	long seconds = end.tv_sec - start.tv_sec;
	long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
	double time_in_sec = micros / 1000000.0;

	std::cout << "Time to process a range of " << size
				<< " elements with " << container << " : "
				<< time_in_sec << " sec" << std::endl;
}

void printVector(const std::vector<int>& vec, const std::string& prefix)
{
	std::cout << prefix;
	if (vec.size() <= 10)
	{
		for (size_t i = 0; i < vec.size(); i++)
			std::cout << vec[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 5; i++)
			std::cout << vec[i] << " ";
		std::cout << "[...] ";
		for (size_t i = vec.size() - 5; i < vec.size(); i++)
			std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int>	createSequenceV(std::vector<int> *v2)
{
	std::vector<int>		jacob;
	size_t					value = 3;
	size_t					prev = 1;
	size_t					jacob_position = 3;

	for (size_t i = 0; i < (v2->size()); i++)
	{
		value = Jacobsthal(jacob_position);
		if (value > v2->size())
		{
			for (size_t i = value; i > prev; i--)
			{
				if (i <= v2->size())
					jacob.push_back(i - 1);
			}
			break ;
		}
		jacob.push_back(value - 1);
		for (size_t i = value - 1; i > prev; i--)
		{
			if (i < v2->size())
				jacob.push_back(i - 1);
		}
		prev = value;
		jacob_position++;
	}
	return (jacob);
}

std::vector<int> InsertionV(std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& jacob, const std::vector<int> &vector, size_t c)
{
	std::vector<int>	newVector;

	for (size_t i = 0; i < jacob.size(); i++)
		v1.insert(lower_bound(v1.begin(), v1.end(), v2[jacob[i]]), v2[jacob[i]]);
	for (size_t i = 0; i < v1.size(); i++)
	{
		for (size_t k = 0; k < vector.size(); k++)
		{
			if (v1[i] == vector[k])
			{
				for(size_t j = c; j > 0; j--)
					newVector.push_back(vector[k - (j - 1)]);
			}
		}
	}
	return (newVector);
}

void	MergeVInsert(std::vector<int> &vector, size_t i, size_t increment, size_t c)
{
	size_t j = i;

	if (i >= vector.size() / 2)
		return ;
	while (j < vector.size())
	{
		if (vector[j] > vector[j + c] && j + c < vector.size())
		{
			for (int k = c; k > 0; k--)
				std::swap(vector[j + k - c], vector[j + k]);
		}
		j += increment;
	}

	MergeVInsert(vector, (c * 2) - 1, increment * 2, c * 2);

	std::vector<int>    v1;
	std::vector<int>    v2;
	std::vector<int>	odd;
	int 			   	flag = 0;

	if (vector.size() % c != 0)
	{
		for (size_t i = vector.size() - (vector.size() % c); i < vector.size(); i++)
			odd.push_back(vector[i]);
	}
	for (size_t k = c; k <= vector.size(); k += c)
	{
		if (k > vector.size())
			break ;
		if (flag == 0)
		{
			v2.push_back(vector[k - 1]);
			flag = 1;
		}
		else
		{
			v1.push_back(vector[k - 1]);
			flag = 0;
		}
	}
	v1.insert(v1.begin(), v2[0]);
	std::vector<int>	jacob = createSequenceV(&v2);
	vector = InsertionV(v1, v2, jacob, vector, c);
	for (size_t i = 0; i < odd.size(); i++)
		vector.push_back(odd[i]);
}


void	PmergeMe::FordjVector(std::vector<int>	&vector)
{
	struct timeval start, end;

	printVector(vector, "Before : ");
	gettimeofday(&start, NULL);
	MergeVInsert(vector, 0, 2, 1);
	gettimeofday(&end, NULL);
	printVector(vector, "After  : ");
	printTime(start, end, vector.size(), "std::vector");
}

void printDeque(const std::deque<int>& deq, const std::string& prefix)
{
	std::cout << prefix;
	if (deq.size() <= 10)
	{
		for (size_t i = 0; i < deq.size(); i++)
			std::cout << deq[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 5; i++)
			std::cout << deq[i] << " ";
		std::cout << "[...] ";
		for (size_t i = deq.size() - 5; i < deq.size(); i++)
			std::cout << deq[i] << " ";
	}
	std::cout << std::endl;
}

std::deque<int> createSequenceD(std::deque<int>* d2)
{
	std::deque<int>	jacob;
	size_t			value = 3;
	size_t			prev = 1;
	size_t			jacob_position = 3;

	for (size_t i = 0; i < d2->size(); i++)
	{
		value = Jacobsthal(jacob_position);
		if (value > d2->size())
		{
			for (size_t i = value; i > prev; i--)
			{
				if (i <= d2->size())
					jacob.push_back(i - 1);
			}
			break;
		}
		jacob.push_back(value - 1);
		for (size_t i = value - 1; i > prev; i--)
		{
			if (i < d2->size())
				jacob.push_back(i - 1);
		}
		prev = value;
		jacob_position++;
	}
	return (jacob);
}

std::deque<int> InsertionD(std::deque<int>& d1, const std::deque<int>& d2, std::deque<int>& jacob, const std::deque<int>& deque, size_t c)
{
	std::deque<int> newDeque;

	for (size_t i = 0; i < jacob.size(); i++)
		d1.insert(std::lower_bound(d1.begin(), d1.end(), d2[jacob[i]]), d2[jacob[i]]);
	for (size_t i = 0; i < d1.size(); i++)
	{
		for (size_t k = 0; k < deque.size(); k++)
		{
			if (d1[i] == deque[k])
			{
				for (size_t j = c; j > 0; j--)
					newDeque.push_back(deque[k - (j - 1)]);
			}
		}
	}
	return (newDeque);
}

void MergeDInsert(std::deque<int>& deque, size_t i, size_t increment, size_t c)
{
	size_t j = i;

	if (i >= deque.size() / 2)
		return;
	while (j < deque.size()) {
		if (deque[j] > deque[j + c] && j + c < deque.size()) {
			for (int k = c; k > 0; k--)
				std::swap(deque[j + k - c], deque[j + k]);
		}
		j += increment;
	}

	MergeDInsert(deque, (c * 2) - 1, increment * 2, c * 2);

	std::deque<int> d1;
	std::deque<int> d2;
	std::deque<int> odd;
	int flag = 0;

	if (deque.size() % c != 0) {
		for (size_t i = deque.size() - (deque.size() % c); i < deque.size(); i++)
			odd.push_back(deque[i]);
	}
	for (size_t k = c; k <= deque.size(); k += c) {
		if (k > deque.size())
			break;
		if (flag == 0) {
			d2.push_back(deque[k - 1]);
			flag = 1;
		} else {
			d1.push_back(deque[k - 1]);
			flag = 0;
		}
	}
	d1.insert(d1.begin(), d2[0]);
	std::deque<int> jacob = createSequenceD(&d2);
	deque = InsertionD(d1, d2, jacob, deque, c);
	for (size_t i = 0; i < odd.size(); i++)
		deque.push_back(odd[i]);
}

void	PmergeMe::FordjDeque(std::deque<int> &deque)
{
	struct timeval start, end;

	printDeque(deque, "Before : ");
	gettimeofday(&start, NULL);
	MergeDInsert(deque, 0, 2, 1);
	gettimeofday(&end, NULL);
	printDeque(deque, "After  : ");
	printTime(start, end, deque.size(), "std::deque");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:22:03 by yu                #+#    #+#             */
/*   Updated: 2024/03/22 01:23:55 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static long	get_time(struct timespec *start, struct timespec *end) {
	return (end->tv_sec - start->tv_sec) * 1000000000L + (end->tv_nsec - start->tv_nsec);
}

void	input_check(char **in, int ac, std::deque<int> & deq, std::list<int> & lst) {
	long	n;
	for (int i = 0; i < ac - 1; i++) {
		for (int j = 0; in[i][j]; j++) {
			if (!std::isdigit(in[i][j])) {
				throw std::exception();
			}
		}
		n = std::strtol(in[i], NULL, 10);
		if (n > INT_MAX)
			throw std::exception();
		deq.push_back(n);
		lst.push_back(n);
	}
}

void	output(char **in, std::deque<int> & deq, long t1, long t2) {\
	int	size = deq.size();
	std::cout << "Before:\t";
	for (int i = 0; i < size; i++) {
		std::cout << in[i] << ' ';
	}
	std::cout << "\nAfter:\t";
	for (int i = 0; i < size; i++) {
		std::cout << deq[i] << ' ';
	}
	std::cout << "\nTime to process a range of " << size << " elements with std::deque\t: " << t1 << " ns\n";
	std::cout << "Time to process a range of " << size << " elements with std::list\t: " << t2 << " ns\n";
}

typedef struct s_pair {
	int	large;
	int	small;
}	t_pair;

static void	merge_deque(std::deque<t_pair> & pairs, const int begin, const int mid, const int end) {
	int	left_size = mid - begin + 1;
	int	right_size = end - mid;

	// copy to tmp arrary left half and right half
	std::deque<t_pair>	left(left_size), right(right_size); // memory alloc at once to reduce time cost
	for (int i = 0; i + begin <= mid; i++)
		left[i] = pairs[i + begin];
	for (int i = 0; i + mid + 1 <= end; i++)
		right[i] = pairs[i + mid + 1];
	// copy ends

	// merge 2 arrays
	int	left_i = 0, right_i = 0;
	while (left_i < left_size && right_i < right_size) {
		if (left[left_i].large < right[right_i].large) {
			pairs[begin + left_i + right_i] = left[left_i];
			left_i++;
		}
		else {
			pairs[begin + left_i + right_i] = right[right_i];
			right_i++;
		}
	}
	for (int i = 0; left_i + i < left_size; i++)
		pairs[begin + left_i + right_i + i] = left[left_i + i];
	for (int i = 0; right_i + i < right_size; i++)
		pairs[begin + left_i + right_i + i] = right[right_i + i];
	//merge ends
}

static void	merge_sort_deque(std::deque<t_pair> & pairs, const int begin, const int end) {
	if (begin >= end)
		return ;
	int	mid = (begin + end) / 2;
	merge_sort_deque(pairs, begin, mid);
	merge_sort_deque(pairs, mid + 1, end);
	merge_deque(pairs, begin, mid, end);
}

// static int	binary_search_deque(std::deque<int> & deq, int tar) {
// 	int	end = deq.size(); //5
// 	int	mid = end / 2; //2
// 	int	start = 0;
// 	while (mid < end && start < mid)
// 	{
// 		if (deq[mid + 1] >= tar && deq[mid] <= tar)
// 			return mid;
// 		if (deq[mid + 1] >= tar && deq[mid] >= tar)
// 			start = mid;
// 		else if (deq[mid + 1] <= tar && deq[mid] <= tar)
// 			end = mid;
// 		mid = (start + end) / 2;
// 	}
// 	throw std::exception();
// }

// static void	insertion_sort_deque(std::deque<int> & deq, std::deque<t_pair> & pairs) {

// }

static void	sort(std::deque<int> & deq) {
	// pair up
	int	extra = -1; //since the input values are all positive
	std::deque<t_pair> pairs;
	if (deq.size() % 2 != 0) { // the odd number input, the last number remained unpaired
		extra = deq[deq.size() - 1];
	}
	unsigned long	pair_size = deq.size() / 2; // will be used later
	for (unsigned long i = 0; i < pair_size; i++) {
		if (deq[i] >= deq[i + pair_size])
			pairs.push_back((t_pair){deq[i], deq[i + pair_size]});
		else
			pairs.push_back((t_pair){deq[i + pair_size], deq[i]});
	}
	// pair up ends

	// merge sort
	merge_sort_deque(pairs, 0, pair_size - 1);
	//merge sort ends

	// re-orgnize deq, pairs
	deq = std::deque<int> (pair_size);
	for (unsigned long i = 0; i < pair_size; i++) {
		deq[i] = pairs[i].large;
	}
	deq.push_front(pairs[0].small);
	pairs.pop_front();
	pair_size = pairs.size();
	// try to make the subsequence to be 1,0,3,2,9,8,7,6,5,4,19,18...
	// the sums of sizes of every two adjacent groups form a sequence of powers of two.
	// Thus, the sizes of groups are: 2, 2, 6, 10, 22, 42 ...
	std::deque<int> unsorted(pair_size);
	unsigned long	cur_pow = 4;
	unsigned long	accu = 2;
	unsigned long	last_group = 2;
	for (unsigned long i = 0; i < pair_size; i++) {
		if (i < 2) {
			unsorted[i] = pairs[1 - i].small;
		}
		else if (cur_pow - last_group < pair_size - accu) {
			unsorted[i] = pairs[cur_pow - (i + 1 - accu)].small;
			if (cur_pow - last_group <= i + 1 - accu) {
				last_group = cur_pow - last_group;
				accu += i + 1 - accu;
				cur_pow *= 2;
				// std::cout << last_group << "\n";
			}
		}
		else {
			unsorted[i] = pairs[pair_size - (i + 1 - accu)].small;
		}
		std::cout << i << ' ' << unsorted[i] << '\n'; // this line checkes if the order is correct
	}
	if (extra != -1)
		unsorted.push_back(extra);
	// re-orgnize ends

	// insertion sort


}

long	merge_insertion_sort_deque(std::deque<int> & deq) {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	// std::sort(deq.begin(), deq.end());
	sort(deq);
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (get_time(&start, &end));
}
long	merge_insertion_sort_list(std::list<int> & lst) {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	(void)lst;
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (get_time(&start, &end));
}

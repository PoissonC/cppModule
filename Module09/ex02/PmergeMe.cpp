/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:22:03 by yu                #+#    #+#             */
/*   Updated: 2024/03/24 18:44:43 by ychen2           ###   ########.fr       */
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
	std::cout << "\nTime to process a range of " << size << " elements with std::deque: " << t1 << " ns\n";
	std::cout << "Time to process a range of " << size << " elements with std::list: " << t2 << " ns\n";
}

typedef struct s_pair {
	int	first;
	int	second;
}	t_pair;

//	deque part

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
		if (left[left_i].first < right[right_i].first) {
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

static int	binary_search_deque(std::deque<int> & deq, int tar, int end) {
	if (deq.empty())
		return -2;
	int	size = deq.size();
	if (end >= size)
		end = size - 1;
	int	start = 0;
	int	mid = start + (end - start) / 2;
	// std::cout << "size: " << size - 1 << " end: " << end << '\n'; // this line make sure the comparison is restricted to a smaller size
	if (tar <= deq[start])
		return -1;
	if (tar >= deq[end])
		return end + 1;
	while (start <= end && mid + 1 < size)
	{
		if (deq[mid + 1] >= tar && deq[mid] <= tar)
			return mid + 1;
		if (deq[mid + 1] >= tar && deq[mid] >= tar)
			end = mid - 1;
		else
			start = mid + 1;
		mid = start + (end - start) / 2;
	}
	return end + 1;
}

static void	insertion_sort_deque(std::deque<int> & deq, std::deque<t_pair> & unsorted) {
	int	size = unsorted.size();
	// for (size_t i = 0; i < deq.size(); i++)
	// 	std::cout << deq[i] << ' ';
	// std::cout << '\n';
	for (int i = 0; i < size; i++) {
		// std::cout << "i: " << i << ", tar: " << unsorted[i].first << ", end: " << unsorted[i].second << '\n';
		int	tar_idx = binary_search_deque(deq, unsorted[i].first, unsorted[i].second);
		if (tar_idx == -1) {
			deq.push_front(unsorted[i].first);
			// if (i + 1 < size)
			// 	unsorted[i + 1].second++;
		}
		else
			deq.insert(deq.begin() + tar_idx, unsorted[i].first);
		//here can optimize the comparison number by adjusting "second"
	}
}

static void	sort_deque(std::deque<int> & deq) {
	// pair up
	int	extra = -1; //since the input values are all positive
	std::deque<t_pair> pairs;
	int	orig_size = deq.size();
	if (orig_size % 2 != 0) { // the odd number input, the last number remained unpaired
		extra = deq[orig_size - 1];
	}
	unsigned long	pair_size = orig_size / 2; // will be used later
	for (unsigned long i = 0; i < pair_size; i++) {
		if (deq[i] >= deq[i + pair_size])
			pairs.push_back((t_pair){deq[i], deq[i + pair_size]});
		else
			pairs.push_back((t_pair){deq[i + pair_size], deq[i]});
	}
	// pair up ends

	merge_sort_deque(pairs, 0, pair_size - 1);

	// re-orgnize deq, pairs
	deq = std::deque<int> (pair_size);
	for (unsigned long i = 0; i < pair_size; i++) {
		deq[i] = pairs[i].first;
	}
	deq.push_front(pairs[0].second);
	pairs.pop_front();
	pair_size = pairs.size();
	// try to make the subsequence to be 1,0,3,2,9,8,7,6,5,4,19,18...
	// the sums of sizes of every two adjacent groups form a sequence of powers of two.
	// Thus, the sizes of groups are: 2, 2, 6, 10, 22, 42 ...
	std::deque<t_pair> unsorted(pair_size);
	unsigned long	cur_pow = 4;
	unsigned long	accu = 2;
	unsigned long	last_group = 2;
	for (unsigned long i = 0; i < pair_size; i++) {
		unsorted[i].second = cur_pow * 2 - 1;
		if (i < 2) {
			if (pair_size < 2)
				unsorted[i].first = pairs[0].second;
			else
				unsorted[i].first = pairs[1 - i].second;
			unsorted[i].second = 3;
		}
		else if (accu + cur_pow - last_group < pair_size) {
			unsorted[i].first = pairs[accu + cur_pow - last_group - (i + 1 - accu)].second;
		}
		else {
			unsorted[i].first = pairs[pair_size - (i + 1 - accu)].second;
		}
		// std::cout << i << ' ' << accu << ' ' << cur_pow << ' ' << last_group << '\n';
		if (cur_pow == i + 1 - accu + last_group) {
			last_group = cur_pow - last_group;
			accu = i + 1;
			cur_pow *= 2;
		}
		// std::cout << i << ' ' << unsorted[i].first << ' ' << unsorted[i].second << '\n'; // this line checkes if the order is correct
	}
	if (extra != -1)
		unsorted.push_back((t_pair){extra, cur_pow * 2});
	// re-orgnize ends

	insertion_sort_deque(deq, unsorted);
}

long	merge_insertion_sort_deque(std::deque<int> & deq) {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	sort_deque(deq);
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (get_time(&start, &end));
}


//	deque part ends

//	list part

bool pair_cmp (t_pair first, t_pair second) {
	return ( first.first < second.first );
}

void split_list(std::list<t_pair> & lst, std::list<t_pair> & lst1, std::list<t_pair> & lst2) {
    // An iterator to the middle of the list
    std::list<t_pair>::iterator it = lst.begin();
    std::advance(it, lst.size() / 2);

    // Split the list into lst1 and lst2
    lst1.splice(lst1.begin(), lst, lst.begin(), it);
    lst2.splice(lst2.begin(), lst);
}

static void	merge_sort_list(std::list<t_pair> & pairs) {
	if (pairs.size() <= 1)
		return;
	std::list<t_pair> lst1, lst2;
    split_list(pairs, lst1, lst2);
	merge_sort_list(lst1);
	merge_sort_list(lst2);
	lst1.merge(lst2, pair_cmp);
	pairs.swap(lst1);
}

static void insertion_sort_list(std::list<int> & lst, std::list<t_pair> & pairs) {
	while (!pairs.empty()) {
		std::list<int>::iterator	lst_it = lst.begin();
		int							size = lst.size();
		for (int i = 0; i < size; i++, lst_it++) {
			if (*lst_it >= (*pairs.begin()).second) {
				lst.insert(lst_it, (*pairs.begin()).second);
				break;
			}
		}
		pairs.pop_front();
	}
}

static void	sort_list(std::list<int> & lst) {
	// pair up
	int	extra = -1; //since the input values are all positive
	std::list<t_pair> pairs;
	int	orig_size = lst.size();
	if (orig_size % 2 != 0) { // the odd number input, the last number remained unpaired
		extra = *(--lst.end());
	}
	unsigned long	pair_size = orig_size / 2; // will be used later
	std::list<int>::iterator it = lst.begin();
	for (unsigned long i = 0; i < pair_size; i++, it++) {
		if (*it >= *(++it)) {
			t_pair	tmp;
			tmp.first = *(--it);
			tmp.second = *(++it);
			pairs.push_back(tmp);
		}
		else {
			t_pair	tmp;
			tmp.first = *(it);
			tmp.second = *(--it);
			pairs.push_back(tmp);
			it++;
		}
	}
	// pair up ends

	merge_sort_list(pairs);

	// no need to re-organize pairs since we can't use [] for list
	// but we need to put pairs back to list
	lst.clear();
	lst.push_back((*pairs.begin()).second);
	for (std::list<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
		lst.push_back((*it).first);
	if (extra != -1)
		(*pairs.begin()).second = extra;
	else
		pairs.pop_front();
	// re-organiz ends

	insertion_sort_list(lst, pairs);

	// for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
	// 	std::cout << (*it) << ' ';
	// }
	// std::cout << '\n';
}

long	merge_insertion_sort_list(std::list<int> & lst) {
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	sort_list(lst);
	clock_gettime(CLOCK_MONOTONIC, &end);
	return (get_time(&start, &end));
}

//	list part ends

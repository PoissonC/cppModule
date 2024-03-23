/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 00:21:58 by yu                #+#    #+#             */
/*   Updated: 2024/03/23 19:52:56 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <string>
#include <locale> //std::isdigit
#include <climits>
#include <time.h>   // time in microseconds

void	input_check(char **in, int ac, std::deque<int> & deq, std::list<int> & lst);
void	output(char **in, std::deque<int> & deq, long t1, long t2);
long	merge_insertion_sort_deque(std::deque<int> & deq);
long	merge_insertion_sort_list(std::list<int> & lst);


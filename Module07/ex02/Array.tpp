/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:22 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 22:09:18 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
Array<T>::Array() : _data(0), _size(0) {
}

template <typename T>
Array<T>::Array(const unsigned int & n) : _data(new T[n]()), _size(n) {
}

template <typename T>
Array<T>::Array(const Array &other) : _data(new T[other._size]()), _size(other._size) {
	for (unsigned int i = 0; i < other._size; i++) {
		this->_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		if (this->_data)
			delete[] this->_data;
		this->_data = new T[other._size]();
		for (unsigned int i = 0; i < other._size; i++) {
			this->_data[i] = other._data[i];
		}
		this->_size = other._size;
	}
	return *this;
}


template <typename T>
Array<T>::~Array() {
	if (this->_data)
    	delete[] this->_data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size) {
		throw out_of_range();
	}
	return this->_data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size) {
		throw out_of_range();
	}
	return *(this->_data + index);
}

template <typename T>
unsigned int	Array<T>::size() const {
	return this->_size;
}

template <typename T>
const char*	Array<T>::out_of_range::what() const throw() {
	return "Index out of bounds";
}

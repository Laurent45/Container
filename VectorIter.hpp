/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:20:30 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/30 16:21:17 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITER_HPP
#define VECTOR_ITER_HPP

#include <cstddef>
#include "iterator.hpp"

template<class T>
class VectorIter {
	public:
		
		// Members Types
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;

		// Constructors
		VectorIter(pointer x) : _ptr(x) {} 
		VectorIter(const VectorIter<T> & copy) : _ptr(copy._ptr) {}

		// Assignement
		VectorIter<T> & operator=(const VectorIter<T> & rhs) {
			if (&rhs != this)
				_ptr = rhs._ptr;
			return (*this);
		}

		// Destructor
		~VectorIter() {}

		// Operator overloading
		bool	operator==(const VectorIter<T> & rhs) const {
			return (this->_ptr == rhs._ptr);
		}

		bool	operator!=(const VectorIter<T> & rhs) const {
			return (this->_ptr != rhs._ptr);
		}

		bool	operator<(const VectorIter<T> & rhs) const {
			return (this->_ptr < rhs._ptr);
		}

		bool	operator>(const VectorIter<T> & rhs) const {
			return (this->_ptr > rhs._ptr);
		}

		bool	operator<=(const VectorIter<T> & rhs) const {
			return (this->_ptr <= rhs._ptr);
		}

		bool	operator>=(const VectorIter<T> & rhs) const {
			return (this->_ptr >= rhs._ptr);
		}

		reference	operator*() {
			return (*_ptr);
		}

		pointer		operator->() {
			return (_ptr);
		}

		VectorIter<T> &		operator++() {
			++_ptr;
			return (*this);
		}

		VectorIter<T>	operator++(int) {
			VectorIter<T> tmp(*this);
			_ptr++;
			return (tmp);
		}

		VectorIter<T> &		operator--() {
			--_ptr;
			return (*this);
		}

		VectorIter<T>	operator--(int) {
			VectorIter<T> tmp(*this);
			_ptr--;
			return (tmp);
		}
		
		VectorIter<T> &	operator+=(difference_type n) {
			difference_type m = n;
			if (m >= 0) {
				while (m) {
					++(*this);
					--m;
				}
			} else {
				while (m) {
					--(*this);
					++m;
				}
			}
			return (*this);
		}

		VectorIter<T>	operator+(difference_type n) {
			VectorIter<T> tmp = *this;
			tmp += n;
			return (tmp);
		}

		VectorIter<T> & operator-=(difference_type n) {
			(*this) += -n;
			return (*this);
		}

		VectorIter<T>	operator-(difference_type n) {
			VectorIter<T> tmp = *this;
			tmp -= n;
			return (tmp);
		}
		
		reference	operator[](difference_type n) {
			return *(*this + n);
		}

		friend VectorIter<T> operator+(difference_type n, const VectorIter<T> & it) {
			VectorIter<T> tmp = it;
			tmp += n;
			return (tmp);
			
		}
		

	private:
		pointer	_ptr;


};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:41:59 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/30 14:57:41 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "VectorIter.hpp"

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class Vector
	{
		private:
			T t[10];

		public:

			VectorIter<T> begin() {
				return (VectorIter<T>(t));
			}

			VectorIter<T> end() {
				return (VectorIter<T>(t+10));
			}

	};

}

#endif

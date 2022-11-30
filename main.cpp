/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrederi <lfrederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:31:16 by lfrederi          #+#    #+#             */
/*   Updated: 2022/11/30 19:37:29 by lfrederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <iostream>

class A {
	public:
		int a;
		int b;

		A(int a = 42, int b = 21) : a(a), b(b) {}

		friend std::ostream & operator<<(std::ostream & out, const A & a)
		{
			out << "a = " << a.a << " | b = " << a.b << "\n";
			return out;
		}
};

int main(void)
{
	ft::Vector<A> vec;
	
	VectorIter<A> it = vec.begin();
	VectorIter<A> ite = vec.end();

	for (VectorIter<A> i(it); i != ite; i++)
		std::cout << *i << "\n";

	for (VectorIter<A> i(it); i != ite; i++)
		std::cout << *i++;

	std::cout << "\n" << it[2];
	/* std::cout << std::endl; */
	/* for (VectorIter<A> i(it); i != ite; i++) */
	/* 	std::cout << *i << "\n"; */
	/*  */
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:22:01 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/17 20:37:13 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <deque>
# include <iostream>

# include "../src/stack.hpp"
# include "utils.cpp"

namespace stack
{
	static void	std_constructor(void)
	{
		std::vector<int> myvector (2,200);        // vector with 2 elements

		std::stack<int> first;                    // empty stack

		std::stack<int,std::vector<int> > second;  // empty stack using vector
		std::stack<int,std::vector<int> > third (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
	}

	static void	ft_constructor(void)
	{
		ft::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack

		ft::stack<int,ft::vector<int> > second;  // empty stack using vector
		ft::stack<int,ft::vector<int> > third (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
	}

	void	std_empty(void)
	{
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}

	void	ft_empty(void)
	{
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}

	void	std_size(void)
	{
		std::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	void	ft_size(void)
	{
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	void	std_top(void)
	{
		std::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

	void	ft_top(void)
	{
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

	void	std_push_pop(void)
	{
		std::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}

	void	ft_push_pop(void)
	{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}

	void	std_relational_operators(void)
	{
		std::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		if (foo==bar) std::cout << "1";
		if (foo!=bar) std::cout << "2";
		if (foo< bar) std::cout << "3";
		if (foo> bar) std::cout << "4";
		if (foo<=bar) std::cout << "5";
		if (foo>=bar) std::cout << "6";
		std::cout << std::endl;
	}

	void	ft_relational_operators(void)
	{
		ft::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		if (foo==bar) std::cout << "1";
		if (foo!=bar) std::cout << "2";
		if (foo< bar) std::cout << "3";
		if (foo> bar) std::cout << "4";
		if (foo<=bar) std::cout << "5";
		if (foo>=bar) std::cout << "6";
		std::cout << std::endl;
	}

	void	std_swaps(void)
	{
		std::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		std::swap(foo,bar);

		std::cout << "size of foo and bar: " << foo.size() << ", " << bar.size();
		std::cout << std::endl;
	}

	void	ft_swaps(void)
	{
		ft::stack<int> foo,bar;
		foo.push (10); foo.push(20); foo.push(30);
		bar.push (111); bar.push(222);

		ft::swap(foo,bar);
		std::cout << "size of foo and bar: " << foo.size() << ", " << bar.size();
		std::cout << std::endl;
	}
}

void	test_stack(void)
{
	header("STACK");
	test_it(stack::ft_constructor, stack::std_constructor, "constructor");
	test_it(stack::ft_empty, stack::std_empty, "empty");
	test_it(stack::ft_size, stack::std_size, "size");
	test_it(stack::ft_top, stack::std_top, "top");
	test_it(stack::ft_push_pop, stack::std_push_pop, "push and pop");
	test_it(stack::ft_relational_operators, stack::std_relational_operators, "operators");
	test_it(stack::ft_swaps, stack::std_swaps, "swap (stack)");
}

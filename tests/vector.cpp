/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:22:01 by mlazzare          #+#    #+#             */
/*   Updated: 2022/04/24 17:12:18 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include	<vector>
# include	<iostream>
# include	<chrono>

# include	"../src/containers/vector.hpp"
# include	"../src/containers/iterator.hpp"
# include   "utils.cpp"

void	std_constructor(void)
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:\n";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_constructor(void)
{
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:\n";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
}

void	std_operator_equal(void)
{
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo and bar:\n" << int(foo.size()) << " and " << int(bar.size());
}

void	ft_operator_equal(void)
{
	ft::vector<int> foo (3,0);
	ft::vector<int> bar (5,0);

	bar = foo;
	foo = ft::vector<int>();

	std::cout << "Size of foo and bar:\n" << int(foo.size()) << " and " << int(bar.size());
}

void	std_begin(void)
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:\n";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_begin(void)
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:\n";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	std_end(void)
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:\n";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_end(void)
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:\n";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	std_rbegin(void)
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:\n";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_rbegin(void)
{
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:\n";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	std_rend(void)
{
	std::vector<int> myvector (5);  // 5 default-constructed ints

	std::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:\n";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_rend(void)
{
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:\n";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
}

void	std_size(void)
{
	std::vector<int> myints;
	std::cout << "size:\n" << myints.size();

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << ", " << myints.size();

	myints.insert (myints.end(),10,100);
	std::cout << ", " << myints.size();

	myints.pop_back();
	std::cout << ", " << myints.size();
}

void	ft_size(void)
{
	ft::vector<int> myints;
	std::cout << "size:\n" << myints.size();

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << ", " << myints.size();

	myints.insert (myints.end(),10,100);
	std::cout << ", " << myints.size();

	myints.pop_back();
	std::cout << ", " << myints.size();
}

void	std_max_size(void)
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size, capacity and max_size:\n" << myvector.size();
	std::cout << ", " << myvector.capacity();
	std::cout << " and " << myvector.max_size();
}

void	ft_max_size(void)
{
	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size, capacity and max_size:\n" << myvector.size();
	std::cout << ", " << myvector.capacity();
	std::cout << " and " << myvector.max_size();
}

void	std_resize(void)
{
	std::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:\n";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
}

void	ft_resize(void)
{
	ft::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:\n";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
}

void	std_capacity(void)
{
	std::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size, capacity and max_size:\n" << myvector.size();
	std::cout << ", " << myvector.capacity();
	std::cout << " and " << myvector.max_size();
}

void	ft_capacity(void)
{
	ft::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size, capacity and max_size:\n" << myvector.size();
	std::cout << ", " << myvector.capacity();
	std::cout << " and " << myvector.max_size();
}

void	std_empty(void)
{
	std::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total:\n" << sum;
}

void	ft_empty(void)
{
	ft::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total:\n" << sum;
}

void	std_reserve(void)
{
	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "capacity changed:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << sz << ", ";
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << sz << ", ";
		}
	}
}

void	ft_reserve(void)
{
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "capacity changed:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << sz << ", ";
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << sz << ", ";
		}
	}
}

void	std_operator_brackets(void)
{
	std::vector<int> myvector (10);   // 10 zero-initialized elements

	std::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
}

void	ft_operator_brackets(void)
{
	ft::vector<int> myvector (10);   // 10 zero-initialized elements

	ft::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
}

void	std_at(void)
{
	std::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
}

void	ft_at(void)
{
	ft::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
}

void	std_front(void)
{
	std::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front();
}

void	ft_front(void)
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front();
}

void	std_back(void)
{
	std::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
}

void	ft_back(void)
{
	ft::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
}

void	std_assign(void)
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size:\n" << int (first.size()) << ", " << int (second.size()) << ", " << int (third.size());
}

void	ft_assign(void)
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size:\n" << int (first.size()) << ", " << int (second.size()) << ", " << int (third.size());
}

void	std_push_back(void)
{
	std::vector<int> myvector;

	for (int i = 0; i < 100; i += 1)
		myvector.push_back (i);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.";
}

void	ft_push_back(void)
{
	ft::vector<int> myvector;

	for (int i = 0; i < 100; i += 1)
		myvector.push_back (i);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.";
}

void	std_pop_back(void)
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum;
}

void	ft_pop_back(void)
{
	ft::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum;
}

void	std_insert(void)
{
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:\n";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
}

void	ft_insert(void)
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	ft::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:\n";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
}

void	std_erase(void)
{
	std::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
}

void	ft_erase(void)
{
	ft::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
}

void	std_swap(void)
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo and bar contain:\n";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];

	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
}

void	ft_swap(void)
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo and bar contain:\n";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];

	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
}

void	std_clear(void)
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
}

void	ft_clear(void)
{
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:\n";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
}

void	std_get_allocator(void)
{
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:\n";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void	ft_get_allocator(void)
{
	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:\n";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void	std_relational_operators(void)
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "1";
	if (foo!=bar) std::cout << "2";
	if (foo< bar) std::cout << "3";
	if (foo> bar) std::cout << "4";
	if (foo<=bar) std::cout << "5";
	if (foo>=bar) std::cout << "6";
}

void	ft_relational_operators(void)
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "1";
	if (foo!=bar) std::cout << "2";
	if (foo< bar) std::cout << "3";
	if (foo> bar) std::cout << "4";
	if (foo<=bar) std::cout << "5";
	if (foo>=bar) std::cout << "6";
}

void	std_swapv(void)
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo and bar contain:\n";
	for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;

	for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
}

void	ft_swapv(void)
{
	ft::vector<int> foo (3,100);   // three ints with a value of 100
	ft::vector<int> bar (5,200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo and bar contain:\n";
	for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;

	for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
}

int	main(void)
{
	test_it(ft_constructor, std_constructor, "constructor");
	test_it(ft_operator_equal, std_operator_equal, "operator=");
	test_it(ft_begin, std_begin, "begin");
	test_it(ft_end, std_end, "end");
	test_it(ft_rbegin, std_rbegin, "rbegin");
	test_it(ft_rend, std_rend, "rend");
	test_it(ft_size, std_size, "size");
	test_it(ft_max_size, std_max_size, "max_size");
	test_it(ft_resize, std_resize, "resize");
	test_it(ft_capacity, std_capacity, "capacity");
	test_it(ft_empty, std_empty, "empty");
	test_it(ft_reserve, std_reserve, "reserve");
	test_it(ft_operator_brackets, std_operator_brackets, "operator[]");
	test_it(ft_at, std_at, "at");
	test_it(ft_front, std_front, "front");
	test_it(ft_back, std_back, "back");
	test_it(ft_assign, std_assign, "assign");
	test_it(ft_push_back, std_push_back, "push_back");
	test_it(ft_pop_back, std_pop_back, "pop_back");
	test_it(ft_insert, std_insert, "insert");
	test_it(ft_erase, std_erase, "erase");
	test_it(ft_swap, std_swap, "swap");
	test_it(ft_clear, std_clear, "clear");
	test_it(ft_get_allocator, std_get_allocator, "get_allocator");
	test_it(ft_relational_operators, std_relational_operators, "operators");
	test_it(ft_swapv, std_swapv, "swap (vector)");
	return (0);
}

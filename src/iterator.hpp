/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:14:41 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/13 09:57:36 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <vector>
# include <cstddef>
# include <iterator>
# include "type_traits.hpp"

namespace ft
{
	// [ ITERATOR TRAITS ]
	template < class Iterator >
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;

		while (first != last)		{	++n; ++first;	};
		return n;
	}
	
	// [ ITERATOR ]
	template < class U >
	class Iterator
	{
		public:

			typedef ptrdiff_t								difference_type;
			typedef U										value_type;
			typedef U*										pointer;
			typedef const U*								const_pointer;
			typedef U&										reference;
			typedef const U&								const_reference;
			typedef std::random_access_iterator_tag			iterator_category;
			typedef Iterator< const U >						const_iterator;

			Iterator(void)					:	_it()		{};
			Iterator(pointer it)			:	_it(it) 	{};
			Iterator(const Iterator& it)	:	_it(it._it) {};
			~Iterator(void)									{};

			pointer			base() const 	{	return  _it;	};

			Iterator	operator = (const Iterator& r)				{	_it = r.base();	return  *this;		};
			Iterator	operator + (difference_type n) const		{	return  Iterator(base() + n);		};
			Iterator&	operator ++ ()								{	_it += 1;	return  *this;			};
			Iterator	operator ++ (int)							{	Iterator(tmp) = *this; _it += 1; return  tmp;	};
			Iterator&	operator += (difference_type n)				{	_it += n;	return  *this;			};

			Iterator	operator - (difference_type n) const 		{ 	return  Iterator(base() - n); 		};
			Iterator&	operator -- ()								{	_it -= 1; return  *this;			};
			Iterator	operator -- (int)							{	Iterator(tmp) = *this; _it--; return  tmp;	}; // to check
			Iterator	operator-=(difference_type n)				{	_it -= n;	return  *this;			};

			reference		operator*() 							{	return  *_it;						};
			const_reference	operator*() const 						{	return  *_it;						};

			pointer			operator->() 							{	return &(operator*());				};
			const_pointer	operator->() const 						{	return &(operator*());				};

			reference		operator[] (difference_type n) 			{	return  base()[n];					};
			const_reference	operator[] (difference_type n) const 	{ 	return  base()[n];					};

			friend Iterator			operator + (difference_type n, Iterator const& r)		{	return r + n;	};
			friend difference_type	operator - (const Iterator& l, const Iterator& r) 		{	return  &(*l) - &(*r);	};

			friend bool		operator == (const Iterator& l, const Iterator& r) 		{	return  l.base() == r.base();	};
			friend bool		operator != (const Iterator& l, const Iterator& r)		{	return  l.base() != r.base();	};
			friend bool		operator > (const Iterator& l, const Iterator& r) 		{	return  l.base() > r.base();	};
			friend bool		operator <= (const Iterator& l, const Iterator& r) 		{	return  l.base() <= r.base();	};
			friend bool		operator < (const Iterator& l, const Iterator& r) 		{	return  l.base() < r.base();	};
			friend bool 	operator >= (const Iterator& l, const Iterator& r) 		{	return  l.base() >= r.base();	};

			operator 	const_iterator () const						{	return const_iterator(_it);		};

		private:

			pointer	_it;
	};

	// [	REVERSE ITERATOR	]
	template <class Iterator>
	class reverse_iterator
	{
		public:

			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;


		protected:
			Iterator _it;

		public:
			reverse_iterator()	:	_it() 					{};
			reverse_iterator(iterator_type it)	:	_it(it) {};

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> & rev_it)	: _it(rev_it.base()) 	{};

			template <class Iter>
			reverse_iterator&	operator=(const reverse_iterator<Iter>& other)				{		_it = other.base(); return  *this;		};

			iterator_type		base() const 												{ 		return _it; 							};

			reference			operator*() const											{		iterator_type	tmp = _it;	return *(--tmp);				};

			reverse_iterator	operator+(difference_type n) const 							{ 		return  reverse_iterator(_it - n); 							};

			reverse_iterator&	operator++()												{		--_it;	return  *this;										};

			reverse_iterator	operator++(int)												{		reverse_iterator tmp = *this; --_it; return  tmp;			};

			reverse_iterator&	operator+=(difference_type n)								{		_it -= n;	return  *this;									};

			reverse_iterator	operator-(difference_type n) const 							{		return  reverse_iterator(_it + n); 							};

			reverse_iterator&	operator--()												{		++_it;	return  *this;										};

			reverse_iterator	operator--(int)												{		reverse_iterator tmp = *this; ++_it; return  tmp;			};

			reverse_iterator	operator-=(difference_type n)								{		_it += n;	return  *this;									};

			pointer				operator->() const 											{		return &(operator*());										};

			reference			operator[] (difference_type n) const 						{		return  base()[-n - 1];										};

	};

	template <class Iter1, class Iter2>
	bool	operator==(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() == r.base(); }

	template <class Iter1, class Iter2>
	bool	operator!=(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() != r.base(); }

	template <class Iter1, class Iter2>
	bool	operator<(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() > r.base(); }

	template <class Iter1, class Iter2>
	bool	operator<=(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() >= r.base(); }

	template <class Iter1, class Iter2>
	bool	operator>(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() < r.base(); }

	template <class Iter1, class Iter2>
	bool 	operator>=(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  l.base() <= r.base(); }

	template <class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it) { return  rev_it + n; }

	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1>& l, const reverse_iterator<Iter2>& r) { return  r.base() - l.base(); }
};

#endif

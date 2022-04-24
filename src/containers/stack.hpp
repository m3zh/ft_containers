/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:35:46 by mlazzare          #+#    #+#             */
/*   Updated: 2022/04/24 16:23:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef ptrdiff_t	size_type;

			explicit			stack(const container_type& c = container_type()): _container(c) {};

			bool				empty() const 				{		return (_container.empty());		};
			size_type			size() const 				{		return (_container.size());		};
			value_type&			top()						{		return (_container.back());		};
			const value_type&	top() const 				{		return (_container.back());		};
			void				push(const value_type& val) {		_container.push_back(val);		};
			void				pop() 						{		_container.pop_back();			};

			friend bool			operator == (const stack<T,Container>& l, const stack< T,Container >& r)
			{		return (l._container == r._container);			};

			friend bool			operator <  (const stack<T,Container>& l, const stack< T,Container >& r)
			{		return (l._container < r._container);			};

		private:
			container_type		_container;
	};

	template <class T, class Container>
	bool						operator != (const stack<T,Container>& l, const stack<T,Container>& r) 
	{	return (!(l == r));		};

	template <class T, class Container>
	bool						operator <= (const stack<T,Container>& l, const stack<T,Container>& r)
	{	return (!(r < l));		};

	template <class T, class Container>
	bool						operator >  (const stack<T,Container>& l, const stack<T,Container>& r)
	{	return (r < l);			};

	template <class T, class Container>
	bool						operator >= (const stack<T,Container>& l, const stack<T,Container>& r)
	{	return (!(l < r));		};
};

#endif

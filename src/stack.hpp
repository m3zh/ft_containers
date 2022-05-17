/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:35:46 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/17 20:43:02 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef ptrdiff_t	size_type;

			// [ MEMBER FUNCTIONS ]
			explicit			stack(const container_type& ctnr = container_type()): c(ctnr) {}

			bool				empty() const 				{	return c.empty();		};
			size_type			size() const				{	return c.size(); 		};
			value_type&			top() 						{	return c.back(); 		};
			const value_type&	top() const 				{	return (c.back());		};
			void				push(const value_type& val) { 	c.push_back(val); 		};
			void				pop() 						{	c.pop_back();			};

			friend bool			operator==(const stack<T,Container>& l, const stack<T,Container>& r)
			{	return (l.c == r.c);	};

			friend bool			operator<(const stack<T,Container>& l, const stack<T,Container>& r)
			{	return (l.c < r.c);		};
			

		protected:
			container_type		c;
	};

	// [ NON MEMBER FUNCTIONS ]
	template <class T, class Container>
	bool						operator!=(const stack<T,Container>& l, const stack<T,Container>& r) { return (!(l == r)); }

	template <class T, class Container>
	bool						operator<=(const stack<T,Container>& l, const stack<T,Container>& r) { return (!(r < l)); }

	template <class T, class Container>
	bool						operator>(const stack<T,Container>& l, const stack<T,Container>& r) { return (r < l); }

	template <class T, class Container>
	bool						operator>=(const stack<T,Container>& l, const stack<T,Container>& r) { return (!(l < r)); }
}

#endif

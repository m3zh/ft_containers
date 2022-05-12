/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:35:46 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/11 19:52:22 by mlazzare         ###   ########.fr       */
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
			explicit			stack(const container_type& ctnr = container_type()): _ctnr(ctnr) {}

			bool				empty() const 				{	return _ctnr.empty();		};
			size_type			size() const				{	return _ctnr.size(); 		};
			value_type&			top() 						{	return _ctnr.back(); 		};
			const value_type&	top() const 				{	return (_ctnr.back());		};
			void				push(const value_type& val) { 	_ctnr.push_back(val); 		};
			void				pop() 						{	_ctnr.pop_back();			};

			friend bool			operator==(const stack<T,Container>& l, const stack<T,Container>& r)
			{	return (l._ctnr == r._ctnr);	};

			friend bool			operator<(const stack<T,Container>& l, const stack<T,Container>& r)
			{	return (l._ctnr < r._ctnr);		};
			

		private:

			container_type		_ctnr;
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

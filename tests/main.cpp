/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:57:16 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/17 20:39:24 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>

# ifndef ALL
# define ALL 0
# endif

# ifndef VECTOR
# define VECTOR 0
# endif

# ifndef MAP
# define MAP 0
# endif

# ifndef STACK
# define STACK 0
# endif

# ifndef SUBJECT
# define SUBJECT 0
# endif

#include <map>
#include <stack>
#include <vector>

#include "map.cpp"
#include "stack.cpp"
#include "vector.cpp"
#include "utils.cpp"
#include "subject.cpp"

int main( void )
{
	if (ALL || VECTOR)
		test_vector();
	if (ALL || MAP)
		test_map();
	if (ALL || STACK)
		test_stack();
	if (SUBJECT)
		test_subject(2);
	return 0;
};
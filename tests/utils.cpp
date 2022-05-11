/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:57:16 by mlazzare          #+#    #+#             */
/*   Updated: 2022/05/11 13:14:28 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <sys/time.h>

void	header(std::string title)
{
	std::cout << "---------------------------\n";
	int space = (20 - title.length()) / 2;
	std::cout << "----";
	for (int i = 0; i < space; i += 1)
		std::cout << " ";
	std::cout << "\x1B[31m" << title << "\033[0m";
	for (int i = 0; i < space; i += 1)
		std::cout << " ";
	std::cout << "----";
    std::cout << "\n---------------------------\n";
}

void	print_timestamp(struct timeval start, struct timeval end)
{
	suseconds_t time_taken;
  
    time_taken = end.tv_usec - start.tv_usec;
    // time_taken = (time_taken + (end.tv_usec - 
    //                           start.tv_usec));

	std::cout << "( " << std::fixed
         << time_taken << std::setprecision(2);
    std::cout << " microsec )" << std::endl;
}

void	test_it(void (*f1)(void), void (*f2)(void), std::string title)
{
	std::cout << std::endl;
	header(title);

	struct timeval start, end;
    gettimeofday(&start, NULL);
	f1();
	gettimeofday(&end, NULL);
	print_timestamp(start, end);

	gettimeofday(&start, NULL);
	f2();
	gettimeofday(&end, NULL);
	print_timestamp(start, end);

	std::cout << std::endl;
}

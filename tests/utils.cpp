/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 08:57:16 by mlazzare          #+#    #+#             */
/*   Updated: 2022/04/24 16:57:51 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>

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

void	test_it(void (*f1)(void), void (*f2)(void), std::string title)
{
	std::cout << std::endl;
	header(title);

	std::cout << "\x1B[36mFT:\033[0m\t\n";
	std::chrono::steady_clock::time_point b1 = std::chrono::high_resolution_clock::now();
	f1();
	std::chrono::steady_clock::time_point e1 = std::chrono::high_resolution_clock::now();
	std::cout << "\n(" << std::chrono::duration_cast<std::chrono::microseconds>(e1 - b1).count() << " microseconds)" << std::endl;

	std::cout << "\x1B[33mSTD:\033[0m\t\n";
	std::chrono::steady_clock::time_point b2 = std::chrono::high_resolution_clock::now();
	f2();
	std::chrono::steady_clock::time_point e2 = std::chrono::high_resolution_clock::now();
	std::cout << "\n(" << std::chrono::duration_cast<std::chrono::microseconds>(e2 - b2).count() << " microseconds)" << std::endl;

	std::cout << std::endl;
}

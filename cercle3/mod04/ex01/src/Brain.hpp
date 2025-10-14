/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:14:44 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 14:31:27 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	~Brain();

	Brain &operator=(const Brain &other);

private:
	std::string _ideas[100];
};

#endif

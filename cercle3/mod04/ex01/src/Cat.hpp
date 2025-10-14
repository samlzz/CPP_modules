/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:32 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 14:23:30 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	~Cat();

	Cat &operator=(const Cat &other);

	void makeSound() const;

private:
	Brain *_brain;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:10:22 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 16:51:47 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource()
	{
	}
	virtual void	  learnMateria(AMateria *)				 = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};
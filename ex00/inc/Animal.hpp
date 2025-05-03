/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 08:54:33 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 08:54:33 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "ansi.h"
#include <string>
#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal &rhs);
		virtual ~Animal(void);
		Animal &operator=(const Animal &rhs);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &out, const Animal &rhs);

#endif

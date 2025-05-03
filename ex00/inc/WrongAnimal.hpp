/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 10:52:29 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 10:52:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "ansi.h"
# include <string>
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &rhs);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(const WrongAnimal &rhs);

		void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;
};

std::ostream &operator<<(std::ostream &out, const WrongAnimal &rhs);

# endif

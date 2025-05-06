/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:22:30 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 17:23:57 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ansi.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(void);
		AMateria(const AMateria &rhs);
		virtual ~AMateria(void);
		AMateria &operator=(const AMateria &rhs);

		std::string const &getType(void) const;
		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string _type;
};

#endif

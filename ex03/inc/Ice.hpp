/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:26:23 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:37 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &rhs);
		virtual ~Ice(void);
		Ice &operator=(const Ice &rhs);

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);
};

#endif

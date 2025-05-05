/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:28:39 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 15:29:29 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &rhs);
		virtual ~Cure(void);
		Cure &operator=(const Cure &rhs);

		virtual AMateria *clone(void) const;
		virtual void use(ICharacter &target);
};

#endif

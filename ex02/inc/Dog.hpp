/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:58:57 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 14:58:33 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &rhs);
		virtual ~Dog(void);
		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
		Brain *getBrain(void) const;

	private:
		Brain *brain;
};

#endif

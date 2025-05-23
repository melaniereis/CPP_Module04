/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 09:58:57 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/05 14:58:48 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &rhs);
		virtual ~Cat(void);
		Cat &operator=(const Cat &rhs);

		void makeSound(void) const;
		Brain *getBrain(void) const;

	private:
		Brain *brain;
};

#endif

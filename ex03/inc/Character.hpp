/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:06:22 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 17:48:20 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "../inc/ICharacter.hpp"
#include "../inc/AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		Character(const Character &rhs);
		virtual ~Character(void);
		Character &operator=(const Character &rhs);

		std::string const &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);

		int getCount(void) const;
		AMateria *getMateria(int idx) const;
		AMateria *getUnequipped(int idx) const;

	private:
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_unequipped[4];
		int _count;
};

// Helper struct for centering text
struct CenterAlign
{
	CenterAlign(const std::string s, int w) : str(s), width(w) {}
	std::string str;
	int width;
};

// Forward declaration of operator<< for CenterAlign and Character
std::ostream &operator<<(std::ostream &os, const CenterAlign &ca);
std::ostream &operator<<(std::ostream &out, const Character &rhs);
#endif

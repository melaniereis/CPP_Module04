/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 13:35:20 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 13:35:20 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "ansi.h"
#include <string>
#include <iostream>
#include <cstdlib>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &rhs);
		virtual ~Brain(void);
		Brain &operator=(const Brain &rhs);

		void setRandomIdeas(void);
		void printIdeas(void) const;
		std::string getIdea(size_t index) const;
	private:
		std::string ideas[100];
};

#endif

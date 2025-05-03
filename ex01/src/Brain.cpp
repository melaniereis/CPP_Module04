/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-03 13:40:03 by meferraz          #+#    #+#             */
/*   Updated: 2025-05-03 13:40:03 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void)
{
	this->setRandomIdeas();
	std::cout << GRN "✅ Brain Default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	std::cout << GRN "✅ Brain Copy constructor called" RESET << std::endl;
	*this = rhs;
}

Brain::~Brain(void)
{
	std::cout << RED "❌ Brain Destructor called" RESET << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)
{
	std::cout << GRN "✅ Brain Copy assignment operator called" RESET << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = rhs.getIdea(i);
	}
	return (*this);
}

std::string Brain::getIdea(size_t index) const
{
	if (index >= 100)
		return ("");
	return (this->ideas[index]);
}

void Brain::setRandomIdeas(void)
{
	const std::string subjects[] =
	{
		"Unicorns", "Dinosaurs", "Robots", "Monsters",
		"Cats", "Aliens", "Bananas", "Shoes", "Clouds",
		"Snails", "Fish", "Mirrors", "Books", "Birds"
	};
	const std::string verbs[] =
	{
		"love", "hate", "see", "hear", "smell",
		"taste", "touch", "play with", "sing to",
		"invent", "translate", "whisper to", "dream about",
		"argue with", "fly across", "build", "dance with",
		"hide", "teleport to"
	};
	const std::string objects[] =
	{
		"the sun", "the stars", "the ocean", "the sky",
		"the forest", "the mountains", "the desert",
		"the city", "the rainbow", "the clouds",
		"the moon", "parallel universes", "spaghetti", "robot dolphins",
		"singing chairs", "invisible cities", "quantum socks",
		"marshmallow storms", "magic portals", "dimension X"
	};

	const int nSubjects = sizeof(subjects) / sizeof(subjects[0]);
	const int nVerbs    = sizeof(verbs) / sizeof(verbs[0]);
	const int nObjects  = sizeof(objects) / sizeof(objects[0]);

	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = subjects[rand() % nSubjects] + " " +
							verbs[rand() % nVerbs] + " " +
							objects[rand() % nObjects] + ".";
	}
}

void Brain::printIdeas(void) const
{
	std::cout << "\n" << MAG << "🧠 Brainstorm Dump (100 ideas):" << RESET << std::endl;
	std::cout << CYN << "──────────────────────────────────────────────" << RESET << std::endl;

	for (int i = 0; i < 100; ++i)
	{
		std::cout << GRN << "[" << (i < 10 ? "0" : "") << i << "] " << RESET
		          << ideas[i] << std::endl;

		// Optional: Add a separator every 10 lines for better readability
		if ((i + 1) % 10 == 0)
		{
			std::cout << CYN << "──────────────────────────────────────────────" << RESET << std::endl;
		}
	}
	std::cout << std::endl;
}

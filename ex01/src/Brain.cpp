/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:40:03 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/06 21:19:07 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/**
 * Default constructor for Brain.
 * Sets all 100 ideas to a random string with 10-50 characters in length.
 * Output a message indicating that the default constructor was called.
 */
Brain::Brain(void)
{
	this->setRandomIdeas();
	std::cout << GRN "✅ Brain Default constructor called" RESET << std::endl;
}

/**
 * Copy constructor for Brain.
 * Calls the copy assignment operator to perform a deep copy.
 * Outputs a message indicating that the copy constructor was called.
 */
Brain::Brain(const Brain &rhs)
{
	std::cout << GRN "✅ Brain Copy constructor called" RESET << std::endl;
	*this = rhs;
}

/**
 * Destructor for Brain.
 * Outputs a message indicating that the destructor was called.
 */
Brain::~Brain(void)
{
	std::cout << RED "❌ Brain Destructor called" RESET << std::endl;
}

/**
 * Copy assignment operator for Brain.
 * Checks for self-assignment and copies the ideas from the rhs object.
 * Outputs a message indicating that the copy assignment operator was called.
 *
 * @param rhs The Brain object to copy from.
 * @return A reference to the current object.
 */
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

/**
 * @brief Retrieves an idea from the Brain.
 *
 * This function returns the idea at the specified index from the Brain's
 * ideas array. If the index is out of bounds (i.e., greater than or equal to
 * 100), an empty string is returned.
 *
 * @param index The index of the idea to retrieve.
 * @return The idea at the specified index, or an empty string if the index is
 *         out of bounds.
 */
std::string Brain::getIdea(size_t index) const
{
	if (index >= 100)
		return ("");
	return (this->ideas[index]);
}

/**
 * Populates the Brain's ideas array with random phrases.
 *
 * This function generates 100 random ideas by combining a random subject,
 * verb, and object from predefined lists. Each idea takes the form of a
 * simple sentence and is stored in the Brain's ideas array.
 */
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

/**
 * Prints all ideas stored in the Brain.
 *
 * This function outputs a formatted list of all 100 ideas currently held
 * within the Brain's ideas array. Each idea is prefixed by its index in
 * the array, formatted with leading zeros for single-digit indices.
 * A separator line is printed every 10 ideas for better readability.
 */

void Brain::printIdeas(void) const
{
	std::cout << "\n" << MAG << "🧠 Brainstorm Dump (100 ideas):" << RESET << std::endl;
	std::cout << CYN << "──────────────────────────────────────────────" << RESET << std::endl;

	for (int i = 0; i < 100; ++i)
	{
		std::cout << GRN << "[" << (i < 10 ? "0" : "") << i << "] " << RESET
		          << ideas[i] << std::endl;

		// Added a separator every 10 lines for better readability
		if ((i + 1) % 10 == 0)
		{
			std::cout << CYN << "──────────────────────────────────────────────" << RESET << std::endl;
		}
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:48:09 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/18 18:50:47 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <cstdlib>
#include <exception>

int main(void)
{
	std::cout << "TIME FOR SOME DOGS:" << std::endl;
	{
		std::cout << "Const Dog:" << std::endl;
		const Animal* j = new Dog();
		std::cout << j->getType() << ": ";
		j->makeSound();
		delete j;
	}
	{
		std::cout << std::endl;
		std::cout << "Dogs without const:" << std::endl;
		Animal* j = new Dog();
		std::cout << j->getType() << ": ";
		j->makeSound();
		for (int i = 0; i < 50; ++i)
		{
			if (i % 2 == 0)
				dynamic_cast<Dog *>(j)->addIdea("I want belly rubs");
			else
				dynamic_cast<Dog *>(j)->addIdea("I want food");
		}
		for (int i = 0; i < 200; ++i)
		{
			try
			{
				std::cout << dynamic_cast<Dog *>(j)->getIdea(i) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				break ;
			}
		}
		Animal* j_copy = new Dog(*dynamic_cast<Dog *>(j));
		delete j;
		std::cout << "\nOriginal deleted.\n" << std::endl;
		std::cout << j_copy->getType() << ": ";
		j_copy->makeSound();
		for (int i = 0; i < 200; ++i)
		{
			try
			{
				std::cout << dynamic_cast<Dog *>(j_copy)->getIdea(i) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				break ;
			}
		}
		delete j_copy;
	}
	std::cout << "\n\nTIME FOR SOME CATS:" << std::endl;
	{
		std::cout << std::endl;
		std::cout << "Const Cat:" << std::endl;
		const Animal* i = new Cat();
		std::cout << i->getType() << ": ";
		i->makeSound();
		delete i;
	}
	{
		std::cout << std::endl;
		std::cout << "Cats without const:" << std::endl;
		Animal* j = new Cat();
		std::cout << j->getType() << ": ";
		j->makeSound();
		for (int i = 0; i < 200; ++i)
			dynamic_cast<Cat *>(j)->addIdea("I am a god! Scratch my belly peasant!");
		for (int i = 0; i < 200; ++i)
		{
			try
			{
				std::cout << dynamic_cast<Cat *>(j)->getIdea(i) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				break ;
			}
		}
		Animal* j_copy = new Cat(*dynamic_cast<Cat *>(j));
		delete j;
		std::cout << "\nOriginal deleted.\n" << std::endl;
		std::cout << j_copy->getType() << ": ";
		j_copy->makeSound();
		for (int i = 0; i < 200; ++i)
		{
			try
			{
				std::cout << dynamic_cast<Cat *>(j_copy)->getIdea(i) << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
				break ;
			}
		}
		delete j_copy;
	}
	return (EXIT_SUCCESS);
}

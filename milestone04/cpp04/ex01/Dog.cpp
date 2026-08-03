#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	_type = other._type;
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete _brain;
		_brain = new Brain(*other._brain);
		_type = other._type;
	}
	std::cout << "Dog Copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i)
{
	return _brain->getIdea(i);
}
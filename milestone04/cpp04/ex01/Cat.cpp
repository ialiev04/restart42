#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	_type = other._type;
	_brain = other._brain; // maybe not a deep copy
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_brain = other._brain; // maybe not a deep copy
		_type = other._type;
	}
	std::cout << "Cat Copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "meow meow" << std::endl;
}
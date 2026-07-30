#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	c->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete c;
	delete i;
	return 0;
}
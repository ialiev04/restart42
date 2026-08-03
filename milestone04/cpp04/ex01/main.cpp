#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// subject test
	const Animal* a = new Dog();
	const Animal* b = new Cat();
	delete a;
	delete b;

	std::cout << std::endl;

	// array test
	Animal* animal_arr[5];
	int i = 0;
	while (i < 5)
	{
		if (i % 2 == 0)
			animal_arr[i] = new Dog();
		else
			animal_arr[i] = new Cat();
		i++;
	}

	std::cout << std::endl;

	i = 0;
	while (i < 5)
	{
		std::cout << animal_arr[i]->getType() << " says:" << std::endl;
		animal_arr[i]->makeSound();
		i++;
	}
	i = 0;
	while (i < 5)
	{
		delete animal_arr[i];
		i++;
	}

	std::cout << std::endl;

	// deep copy test cat
	Cat cat;
	Cat copy_cat(cat);
	
	std::cout << std::endl;

	std::cout << "idea 10 from cat: " << cat.getIdea(10) << std::endl;
	cat.setIdea(10, "tuna");
	std::cout << "new idea 10 from cat: " << cat.getIdea(10) << std::endl;
	std::cout << "idea 10 from copy_cat: " << copy_cat.getIdea(10) << std::endl;

	std::cout << std::endl;

	// deep copy test dog
	Dog dog;
	Dog assignment_dog(dog);
	std::cout << std::endl;
	
	std::cout << "idea 10 from dog: " << dog.getIdea(10) << std::endl;
	dog.setIdea(10, "I like it here ");
	std::cout << "new idea 10 from dog: " << dog.getIdea(10) << std::endl;
	std::cout << std::endl;

	std::cout << "idea 10 from assignment_dog before assignment: " << assignment_dog.getIdea(10) << std::endl;
	assignment_dog = dog;
	std::cout << "idea 10 from assignment_dog after assignment: " << assignment_dog.getIdea(10) << std::endl;
	std::cout << std::endl;

	assignment_dog.setIdea(10, "I don't like it here");
	std::cout << "new idea 10 from assignment dog: " << assignment_dog.getIdea(10) << std::endl;
	std::cout << "idea 10 from dog: " << dog.getIdea(10) << std::endl;

	std::cout << std::endl;

	return 0;
}
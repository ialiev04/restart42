#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void		makeSound() const override;
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);

	private:
		Brain *_brain;
};

#endif
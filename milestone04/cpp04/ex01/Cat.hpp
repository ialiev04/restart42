#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void		makeSound() const override;
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);

	private:
		Brain *_brain;
};

#endif
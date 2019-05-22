#ifndef HUMAN_H
# define HUMAN_H
#include <iostream>
#include "Brain.hpp"

class Human: public Brain
{
	public:
		Human(void);
		~Human(void);

		Brain	getBrain(void);
		std::string	identify();

	private:
		Brain		_brain;
};

#endif
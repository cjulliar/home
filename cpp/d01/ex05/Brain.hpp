#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
# include <sstream>

class Brain
{
	public:
		Brain(void);
		~Brain(void);

		std::string	identify();

	private:
		std::string _address;
};

#endif
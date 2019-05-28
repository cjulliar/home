#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
# include <fstream>

class Intern: public Form
{
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const &src);
		Intern	&operator=(Intern const &rhs);

		Form	*makeForm(std::string form, std::string target);
	
};

#endif
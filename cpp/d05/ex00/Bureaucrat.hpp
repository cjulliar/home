#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int note);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);
		Bureaucrat	&operator=(Bureaucrat const &rhs);

	private:
		std::string	_name;
		int			_note;	
};

std::ostream 	&operator<<(std::ostream &out, Bureaucrat const &rhs);

#endif
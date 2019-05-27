#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
	public:
		Form(void);
		Form(std::string name)
		Form(Form const &src);
		~Form(void);
		Form	&operator=(Form const &rhs);

		bool		getSigned(void) const;
		std::string	getName(void) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error. this bureaucrat has grade too hight");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error. this bureaucrat has grade too low");
				}
		};

	private:
		std::string	const	_name;
		bool				_isSigned;

};

std::ostream 	&operator<<(std::ostream &out, Form const &rhs);

#endif
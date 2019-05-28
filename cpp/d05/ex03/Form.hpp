#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(std::string name, std::string target, int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		~Form(void);
		Form	&operator=(Form const &rhs);

		bool			getSigned(void) const;
		std::string		getName(void) const;
		std::string		getTarget(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(Bureaucrat bureaucrat);

		virtual void	execute(Bureaucrat const &executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("his grade too hight");
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("his grade too low");
				}
		};
		class NoSignException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("this form is not signed");
				}
		};

	protected:
		std::string	const	_name;
		std::string	const	_target;
		bool				_isSigned;
		int	const			_gradeToSign;
		int	const			_gradeToExecute;

};

std::ostream 	&operator<<(std::ostream &out, Form const &rhs);

#endif
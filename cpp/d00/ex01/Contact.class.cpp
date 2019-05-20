#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}


std::string		Contact::getFirstName(void) const
{
	return this->_firstName;
}
int				Contact::setFirstName(std::string fn)
{
	int		i = 0;
	while (fn[i] != '\0')
	{
		if (fn[i] >= '0' && fn[i] <= '9')
		{
			std::cout << "Error: number in first name" << std::endl;
			return (0);
		}
		i = i+1;
	}
	if (i > 0)
		this->_firstName = fn;
	return (1);
}


std::string		Contact::getLastName(void) const
{
	return this->_lastName;
}
int				Contact::setLastName(std::string ln)
{
	int		i = 0;
	while (ln[i] != '\0')
	{
		if (ln[i] >= '0' && ln[i] <= '9')
		{
			std::cout << "Error: number in last name" << std::endl;
			return (0);
		}
		i = i+1;
	}
	if (i > 0)
		this->_lastName = ln;
	return (1);
}


std::string		Contact::getNickName(void) const
{

	return this->_nickName;
}
int				Contact::setNickName(std::string nn)
{
	int		i = 0;
	while (nn[i] != '\0')
	{
		if (nn[i] >= '0' && nn[i] <= '9')
		{
			std::cout << "Error: number in nick name" << std::endl;
			return (0);
		}
		i = i+1;
	}
	if (i > 0)
		this->_nickName = nn;
	return (1);
}


std::string		Contact::getLogin(void) const
{
	return this->_login;
}
void			Contact::setLogin(std::string l)
{
	this->_login = l;
	return ;
}


std::string		Contact::getPostalAdress(void) const
{
	return this->_postalAddress;
}
void			Contact::setPostalAdress(std::string pa)
{
	this->_postalAddress = pa;
	return ;
}


std::string		Contact::getPhoneNumber(void) const
{

	return this->_phoneNumber;
}
int				Contact::setPhoneNumber(std::string pn)
{
	int		i = 0;
	while (pn[i] != '\0')
	{
		if ((pn[i] < '0' || pn[i] > '9') && pn[i] != '+')
		{
			std::cout << "Error: wrong character in phone number" << std::endl;
			return (0);
		}
		i = i+1;
	}
	if (i > 0)
		this->_phoneNumber = pn;
	return (1);
}

std::string		Contact::getBirthdayDate(void) const
{
	return this->_birthdayDate;
}
void			Contact::setBirthdayDate(std::string bd)
{
	this->_birthdayDate = bd;
	return ;
}


std::string		Contact::getFavoriteMeal(void) const
{
	return this->_favoriteMeal;
}
void			Contact::setFavoriteMeal(std::string fm)
{
	this->_favoriteMeal = fm;
	return ;
}


std::string		Contact::getUnderwearColor(void) const
{
	return this->_underwearColor;
}
void			Contact::setUnderwearColor(std::string uc)
{
	this->_underwearColor = uc;
	return ;
}


std::string		Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}
void			Contact::setDarkestSecret(std::string ds)
{
	this->_darkestSecret = ds;
	return ;
}
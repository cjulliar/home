#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
#include <iostream>

class Contact
{

public:
	Contact(void);
	~Contact(void);

	std::string		getFirstName(void) const;
	int				setFirstName(std::string);
	std::string		getLastName(void) const;
	int				setLastName(std::string);
	std::string		getNickName(void) const;
	int				setNickName(std::string);
	std::string		getLogin(void) const;
	void			setLogin(std::string);
	std::string		getPostalAdress(void) const;
	void			setPostalAdress(std::string);
	std::string		getPhoneNumber(void) const;
	int				setPhoneNumber(std::string);
	std::string		getBirthdayDate(void) const;
	void			setBirthdayDate(std::string);
	std::string		getFavoriteMeal(void) const;
	void			setFavoriteMeal(std::string);
	std::string		getUnderwearColor(void) const;
	void			setUnderwearColor(std::string);
	std::string		getDarkestSecret(void) const;
	void			setDarkestSecret(std::string);

private:
	std::string 	_firstName;
	std::string		_lastName;
	std::string		_nickName;
	std::string		_login;
	std::string		_postalAddress;
	std::string		_phoneNumber;
	std::string		_birthdayDate;
	std::string		_favoriteMeal;
	std::string		_underwearColor;
	std::string		_darkestSecret;
};

#endif
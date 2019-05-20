#include "Contact.class.hpp"
#include <vector>

std::string 			ten_carac(std::string str)
{
	std::string rep;

	if (str.length() >= 10)
	{
		rep.append(str, 0, 9);
		rep.append(".");
	}
	else
	{
		for (int i = 0; i < 10 - str.length(); ++i)
		{
			rep.append(" ");
		}
		rep.append(str);
	}
	return (rep);
}

void					print_menu(Contact contact, int index)
{
	std::cout << "         ";
	std::cout << index;
	std::cout << "|";
	std::cout << ten_carac(contact.getFirstName());
	std::cout << "|";
	std::cout << ten_carac(contact.getLastName());
	std::cout << "|";
	std::cout << ten_carac(contact.getNickName());
	std::cout << std::endl;
}

void					print_contact(Contact contact)
{
	std::cout << "First name:      ";
	std::cout << contact.getFirstName() << std::endl;
	std::cout << "Last name:       ";
	std::cout << contact.getLastName() << std::endl;
	std::cout << "Nick name:       ";
	std::cout << contact.getNickName() << std::endl;
	std::cout << "Login:           ";
	std::cout << contact.getLogin() << std::endl;
	std::cout << "Postal adress:   ";
	std::cout << contact.getPostalAdress() << std::endl;
	std::cout << "Birthday date:   ";
	std::cout << contact.getBirthdayDate() << std::endl;
	std::cout << "Favorite meal:   ";
	std::cout << contact.getFavoriteMeal() << std::endl;
	std::cout << "Underwear color: ";
	std::cout << contact.getUnderwearColor() << std::endl;
	std::cout << "Darkest secret:  ";
	std::cout << contact.getDarkestSecret() << std::endl;
}

std::vector<Contact>	add_contact(std::vector<Contact> my_phone_book)
{
	Contact 	contact;
	std::string	read_tmp;
	int			record;

	record = 0;
	while (record == 0)
	{
		std::cout << "First name:" << std::endl;
		getline(std::cin, read_tmp);
		record = contact.setFirstName(read_tmp);
	}

	record = 0;
	while (record == 0)
	{
		std::cout << "Last name:" << std::endl;
		getline(std::cin, read_tmp);
		record = contact.setLastName(read_tmp);
	}

	record = 0;
	while (record == 0)
	{
		std::cout << "Nick name:" << std::endl;
		getline(std::cin, read_tmp);
		record = contact.setNickName(read_tmp);
	}

	std::cout << "Login:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setLogin(read_tmp);

	std::cout << "Postal adress:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setPostalAdress(read_tmp);

	record = 0;
	while (record == 0)
	{
		std::cout << "Phone number:" << std::endl;
		getline(std::cin, read_tmp);
		record = contact.setPhoneNumber(read_tmp);
	}

	std::cout << "Birthday:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setBirthdayDate(read_tmp);

	std::cout << "Favorite meal:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setFavoriteMeal(read_tmp);

	std::cout << "Underwear color:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setUnderwearColor(read_tmp);

	std::cout << "Darkest secret:" << std::endl;
	getline(std::cin, read_tmp);
	contact.setDarkestSecret(read_tmp);


	my_phone_book.push_back(contact);
	return (my_phone_book);
}

int						main()
{
	std::vector<Contact> 	my_phone_book;
	std::string 			command;
	std::string 			snum_contact;
	int						index;
	int 					inum_contact;

	index = 0;
	while (command != "EXIT")
	{
		if (index == 0)
			std::cout << "you can ADD a contact. Else you can EXIT" << std::endl;
		else if (index < 8)
			std::cout << "you can ADD or SEARCH a contact. Else you can EXIT" << std::endl;
		else
			std::cout << "you can SEARCH a contact or you can EXIT" << std::endl;
		getline(std::cin, command);
		if (command == "ADD" && index < 8)
		{
			index += 1;
			my_phone_book = add_contact(my_phone_book);
		}
		else if (command == "SEARCH" && index > 0)
		{
			std::cout << "     index|First Name| Last Name| Nick Name" << std::endl;
			for (int i = 0; i < index; ++i)
			{
				print_menu(my_phone_book[i], i);
			}
			inum_contact = -1;
			snum_contact = "";
			while ((inum_contact < 0 || inum_contact >= index) && snum_contact != "EXIT")
			{
				std::cout << "Which contact would you like read ? or EXIT" << std::endl;
				getline(std::cin, snum_contact);
				inum_contact = snum_contact[0] - 48;
			}
			if (inum_contact >= 0)
				print_contact(my_phone_book[inum_contact]);
		}
	}
	return 0;
}
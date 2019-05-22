#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void)
{
	// Brain my_brain;
	// this->_brain = my_brain;
	return ;
}

Human::~Human(void)
{
	return ;
}

Brain			Human::getBrain(void)
{
	return this->_brain;
}

std::string			Human::identify(void)
{
	return this->_brain.identify();
}
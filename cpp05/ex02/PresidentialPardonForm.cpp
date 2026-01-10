#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 145, 137), _target(""){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
	: AForm("PresidentialPardonForm", 145, 137), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm(other), _target(other.getTarget()) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

//getter
const std::string	&PresidentialPardonForm::getTarget() const{
	return (this->_target);
}

//executor
void PresidentialPardonForm::executeAction() const {
	std::cout << this->getTarget() << " has been pardoned by  Zaphod Beeblebrox." << std::endl;
}

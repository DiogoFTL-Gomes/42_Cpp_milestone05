#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 145, 137), _target(""){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 145, 137), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm(other), _target(other.getTarget()) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

//getter
const std::string	&RobotomyRequestForm::getTarget() const{
	return (this->_target);
}
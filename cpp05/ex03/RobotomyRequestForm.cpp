#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target(""){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target){
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

//executor
void RobotomyRequestForm::executeAction() const {
	std::cout << "******  DrrriDRRrriiDrrrriillliiiiiiiiiinnng noises  ******" << std::endl;
	if (std::rand() % 2){
		std::cout << this->getTarget() << YEL " has been successfully robotomized!!" reset << std::endl;
	}
	else{
		std::cout << RED "Sorry, the Robotomy has failed." reset << std::endl;
	}
}
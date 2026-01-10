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

//executor
void RobotomyRequestForm::executeAction() const {
	std::cout << "\n******  DrrriDRRrriiDrrrriillliiiiiiiiiinnng noises  ******" << std::endl;
	if (rand() % 2){
		std::cout << this->getName() << " has been successfully robotomized!!" << std::endl;
	}
	else{
		std::cout << "Sorry, the Robotomy has failed." << std::endl;
	}
}
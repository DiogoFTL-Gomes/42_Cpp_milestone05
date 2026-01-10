#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target(""){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm(other), _target(other.getTarget()) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

//getter
const std::string	&ShrubberyCreationForm::getTarget() const{
	return (this->_target);
}

//executor
void ShrubberyCreationForm::executeAction() const {
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "  🌳\n";
	file << " 🌲🌲\n";
	file << "🌳🌳🌳\n";
}
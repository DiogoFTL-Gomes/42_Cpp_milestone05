#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib>

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
	int height = (std::rand() % 5) + 3;
	std::ofstream file(("shrubbery_" +_target).c_str());

	for (int row = 0; row < height; row++)
	{
		for (int space = 0; space < height - row - 1; space++)
			file << " ";
		for (int leaf = 0; leaf < (row * 2) + 1; leaf++)
			file << "*";

		file << "\n";
	}
	for (int t = 0; t < 2; t++)
	{
		for (int space = 0; space < height - 1; space++)
			file << " ";
		file << "|\n";
	}
}
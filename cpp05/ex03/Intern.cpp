#include "Intern.hpp"
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &other){
	(void)other;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	return (*this);
}

Intern::~Intern(){
}


AForm* Intern::createShrubbery(const std::string& target){
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(const std::string& target){
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPardon(const std::string& target){
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(const std::string &name, const std::string &target){
	typedef AForm* (*FormCreator)(const std::string&);

	std::string	formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	for (int i = 0; i < 3; i++){
		if (name == formNames[i]){
			std::cout << GRN "Intern creates " reset << name << std::endl;
			return (creators[i](target));
		}
	}
	std::cout << RED "Intern could not create " reset << name << RED " form" reset << std::endl;
	return (NULL);
}

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int	randInt(int min, int max){
	return (min + (std::rand() % (max - min + 1)));
}

int	countStaff(Bureaucrat *const *staff){
	int i = 0;

	while (staff[i])
		i++;
	return (i);
}

int	countDocs(AForm *const *folder){
	int i = 0;

	while (folder[i])
		i++;
	return (i);
}

void	hireStaff(Bureaucrat **staff){
	int i = 0;

	staff[i] = new Bureaucrat("Toni", randInt(140, 150));
	std::cout << *staff[i++] << YEL " has been hired." reset << std::endl;
	staff[i] = new Bureaucrat("Armando", randInt(75, 139));
	std::cout << *staff[i++] << YEL " has been hired." reset << std::endl;
	staff[i] = new Bureaucrat("Esmeraldina", randInt(25, 75));
	std::cout << *staff[i++] << YEL " has been hired." reset << std::endl;
	staff[i] = new Bureaucrat("Gervazio", randInt(5, 25));
	std::cout << *staff[i++] << YEL " has been hired." reset << std::endl;
	staff[i] = new Bureaucrat("Tiburcia", randInt(1, 5));
	std::cout << *staff[i++] << YEL " has been hired." reset << std::endl;
}

void	signingForms(Bureaucrat **staff, AForm **folder){
	for (int i = 0; folder[i]; i++){
		std::cout << CYN "\nForm to sign nº" << i + 1 << ": " << folder[i]->getName() << reset << std::endl;
		for (int j = 0; staff[j]; j++){
			staff[j]->signForm(*folder[i]);
		}
	}
}

void	execForms(Bureaucrat **staff, AForm **folder){
	for (int i = 0; folder[i]; i++){
		std::cout << CYN "\n" << "Form to execute nº" << i + 1 << ": " reset << folder[i]->getName() << std::endl;
		for (int j = 0; staff[j]; j++){
			staff[j]->executeForm(*folder[i]);
			if (staff[j]->getGrade() <= folder[i]->getToExecGrade()){
				break;
			}
		}
	}
}

std::string getTarget(int form){
	std::string targets[3][10] = {
		{
			"bathroom",
			"bocal",
			"elevator",
			"server_room",
			"cluster_01",
			"roof",
			"lounge",
			"cluster_02",
			"meeting_room",
			"coffee_machine"
		},
		{
			"Al Capone",
			"Ted Bundy",
			"Jeffrey Dahmer",
			"Pablo Escobar",
			"John Dillinger",
			"Jesse James",
			"Adolph Hitler",
			"Jack the ripper",
			"Charles Ponzi",
			"John Gotti"
		},
		{
			"Napoleon_Bonaparte",
			"Genghis_Khan",
			"Julius_Caesar",
			"Henry_VIII",
			"Machiavelli",
			"Caligula",
			"Attila_the_Hun",
			"Ivan_the_Terrible",
			"Cesare_Borgia",
			"Rasputin"
		}
	};
	return (targets[form][randInt(0, 9)]);
}

int	main(void){
	Bureaucrat	*staff[6] = {0};
	AForm		*mixFormFolder[16] = {0};
	Intern		newGuy;
	std::string	typeOfForm[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	std::srand(std::time(NULL));

	try{
		hireStaff(staff);
	}
	catch (std::exception &e){
		std::cout << RED "Only " << countStaff(staff) 
		<< " were hired due to: " << e.what() << reset << std::endl;
	}

	for (int i = 0; i < 15; i++){
		try{
			int rSeed = randInt(0, 2);
			mixFormFolder[i] = newGuy.makeForm(typeOfForm[rSeed], getTarget(rSeed));
		}
		catch (std::exception &e){
			std::cout << RED "Intern has failed to create form because " reset
			<< e.what() << std::endl;
			--i;
		}
	}
	signingForms(staff, mixFormFolder);
	execForms(staff, mixFormFolder);

	newGuy.makeForm("Hire intern", "New guy");
	newGuy.makeForm("Pay overtime", "New guy");
	newGuy.makeForm("Paid vacation", "New guy");
	newGuy.makeForm("Fight the power!!", "New guy");

	for (int i = 0; mixFormFolder[i]; i++){
		delete mixFormFolder[i];
	}
	for (int i = 0; staff[i]; i++){
		delete staff[i];
	}
	return (0);
}
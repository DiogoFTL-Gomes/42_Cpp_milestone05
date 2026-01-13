#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
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

void	createRobotomy(AForm **folder){
	const char *criminals[10] = {
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
	};
	for (int i = 0; i < 10; i++){
		folder[i] = new RobotomyRequestForm(criminals[i]);
	}
}

void	createShrubbery(AForm **folder){
	const char *places[10] = {
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
	};
	for (int i = 0; i < 10; i++){
		folder[i] = new ShrubberyCreationForm(places[i]);
	}
}

void	createPardon(AForm **folder){
	const char *people[10] = {
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
	};
	for (int i = 0; i < 10; i++){
		folder[i] = new PresidentialPardonForm(people[i]);
	}
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

int	main(void){
	Bureaucrat	*staff[6] = {0};
	AForm		*robotomyFolder[11] = {0};
	AForm		*shrubberyFolder[11] = {0};
	AForm		*pardonFolder[11] = {0};

	std::srand(std::time(NULL));

	try{
		hireStaff(staff);
	}
	catch (std::exception &e){
		std::cout << RED "Only " << countStaff(staff) 
		<< " were hired due to: " << e.what() << reset << std::endl;
	}

	try{
		createShrubbery(shrubberyFolder);
	}
	catch (std::exception &e){
		std::cout << RED "System created an invalid form!\nError: " 
		<< e.what() << "\nSystem made " << countDocs(shrubberyFolder) << " forms and stopped," reset << std::endl; 
	}
	signingForms(staff, shrubberyFolder);
	execForms(staff, shrubberyFolder);

	try{
		createPardon(pardonFolder);
	}
	catch (std::exception &e){
		std::cout << RED "System created an invalid form!\nError: " 
		<< e.what() << "\nSystem made " << countDocs(pardonFolder) << " forms and stopped," reset << std::endl; 
	}
	signingForms(staff, pardonFolder);
	execForms(staff, pardonFolder);

	try{
		createRobotomy(robotomyFolder);
	}
	catch (std::exception &e){
		std::cout << RED "System created an invalid form!\nError: " 
		<< e.what() << "\nSystem made " << countDocs(robotomyFolder) << " forms and stopped," reset << std::endl; 
	}
	signingForms(staff, robotomyFolder);
	execForms(staff, robotomyFolder);

	for (int i = 0; staff[i] ; i++){
		delete staff[i];
	}
	for (int i = 0; robotomyFolder[i] ; i++){
		delete robotomyFolder[i];
	}
	for (int i = 0; pardonFolder[i] ; i++){
		delete pardonFolder[i];
	}
	for (int i = 0; shrubberyFolder[i] ; i++){
		delete shrubberyFolder[i];
	}
	return (0);
}
#include "Bureaucrat.hpp"
#include "Form.hpp"
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

int	countDocs(Form *const *folder){
	int i = 0;

	while (folder[i])
		i++;
	return (i);
}

void	hireStaff(Bureaucrat **staff){
	int i = 0;

	staff[i] = new Bureaucrat("Toni", randInt(71, 150));
	std::cout << *staff[i++] << YEL " has been hired," reset << std::endl;
	staff[i] = new Bureaucrat("Armando", randInt(21, 70));
	std::cout << *staff[i++] << YEL " has been hired," reset << std::endl;
	staff[i] = new Bureaucrat("Esmeraldina", randInt(1, 20));
	std::cout << *staff[i++] << YEL " has been hired," reset << std::endl;
	staff[i] = new Bureaucrat("Gervazio", randInt(75, 200));
	std::cout << *staff[i++] << YEL " has been hired," reset << std::endl;
	staff[i] = new Bureaucrat("America", randInt(-50, 100));
	std::cout << *staff[i++] << YEL " has been hired," reset << std::endl;
}

void	createDocs(Form **folder){
	int	i = 0;

	folder[i] = new Form("Toilet Use", randInt(1, 20), 150);
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Wash hands", randInt(5, 30), randInt(120, 130));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Eat in 30min", randInt(1, 20), randInt(145, 150));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Mandatory Positivity Survey", randInt(10, 40), randInt(80, 120));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Request To Sit Down", randInt(50, 100), randInt(100, 140));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Approval To Speak In Meetings", randInt(1, 10), randInt(10, 50));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Overtime Without Compensation Agreement", randInt(-10, 20), randInt(140, 180));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Permission To Feel Burnout", randInt(0, 5), randInt(150, 200));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Voluntary Mandatory Team Building", randInt(-50, 10), randInt(-20, 160));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
	folder[i] = new Form("Request To Leave Before Collapse", randInt(140, 200), randInt(1, 300));
	std::cout << YEL "\n--- Form created ---\n" reset << *folder[i++] << std::endl;
}

void	getToWork(Bureaucrat **staff, Form **folder){
	for (int i = 0; folder[i]; i++){
		std::cout << std::endl;
		for (int j = 0; staff[j]; j++){
			staff[j]->signForm(*folder[i]);
		}
	}
}

void	reviewDay(int nStaff, int nForm, Form **folder){
	int countSigned = 0;

	for (int i = 0; folder[i]; i++){
		if (folder[i]->getIsSigned() == true)
			countSigned++;
	}
	std::cout << "\nThis office, while employing " << nStaff 
	<< " people, managed to sign " << countSigned << " of " 
	<< nForm << " forms." << std::endl;
}

int	main(void){
	Bureaucrat	*staff[6] = {0};
	Form		*folder[11] = {0};

	std::srand(std::time(NULL));

	try{
		hireStaff(staff);
	}
	catch (std::exception &e){
		std::cout << RED "Only " << countStaff(staff) 
		<< " were hired due to: " << e.what() << reset << std::endl;
	}

	try{
		createDocs(folder);
	}
	catch (std::exception &e){
		std::cout << RED "System created an invalid document!\nError: " 
		<< e.what() << "\nSystem made " << countDocs(folder) << " forms and stopped," reset << std::endl; 
	}

	getToWork(staff, folder);
	reviewDay(countStaff(staff), countDocs(folder), folder);

	for (int i = 0; i < 5; i++){
		if (!staff[i])
			break;
		delete staff[i];
	}
	for (int i = 0; i < 10; i++){
		if (!folder[i])
			break;
		delete folder[i];
	}
	return (0);
}
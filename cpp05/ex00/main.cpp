#include "Bureaucrat.hpp"

#define reset "\e[0m"
#define RED "\e[0;31m"
#define YEL "\e[0;33m"

int	main(void){
	//Creating top ranking bureaucrat
	Bureaucrat boss("Almeida", 2);
	std::cout << "A bureaucrat has been created:\n" << boss << "\n" << std::endl;
	//Getting rank to the top. Experimenting with loops inside try catch
	std::cout << YEL << boss.getName() << " bureaucrat is greedy and tries to get a better rank,\nbut he forgets that bureaucracy is inefficient:" reset << std::endl;
	for (int i = 0; i < 6; i++){
		try{
			if (i % 3 != 0){
				boss.incrementGrade();
			}
			else{
				boss.decrementGrade();
			}
			std::cout << "A bureaucrat is now:\n" << boss << "\n" << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << std::endl;
			std::cout << RED "Bureaucrat is still:\n" << boss << reset "\n" << std::endl;
		}
	}

	std::cout << YEL << boss.getName() << " is a boss and needs to get someone to do all the real work:" reset << std::endl;
	//Creating basic bureaucrat
	Bureaucrat intern("Manelino", 150);
	std::cout << "A bureaucrat has been created:\n" << intern << "\n" << std::endl;

	//Moving grade past lower limit
	std::cout << YEL << boss.getName() << " thinks that " << intern.getGrade() << " is too much power in the hands of an intern and tries to demote him:" reset << std::endl;
	try{
		intern.decrementGrade();
		std::cout << "A bureaucrat is now:\n" << intern << "\n" << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << std::endl;
		std::cout << RED"Bureaucrat is still:\n" << intern << "\n" reset << std::endl;
	}

	//setting up operator= example
	std::cout << YEL << "Fustrated, " << boss.getName() << " lets " << intern.getName() << " get to work. After a few weeks he decides to spread the wealth...by hiring his wife´s cousin:" reset << std::endl;
	Bureaucrat nepoBaby("Silva", 50);
	std::cout << "A third bureaucrat has been created:\n" << nepoBaby << "\n" << std::endl;
	
	std::cout << YEL << intern.getName() << " is furious! He slaves way and nepotism wins the day!! He goes on strike!\n" << boss.getName() << " knows that if he raises " << intern.getName() << "'s rank, he'll never work properly again.\nA new intern must be hired to pick up the slack" reset << std::endl;
	Bureaucrat newIntern(intern);
	std::cout << "A new bureaucrat has been created:\n" << newIntern << "\n" << std::endl;
	intern = nepoBaby;
	std::cout << "The old intern is now:\n" << intern << "\n" << std::endl;
	for (int i = 0; i < 5; i++){
		try{
			intern.decrementGrade();
			std::cout << "The old intern has been demoted:\n" << intern << "\n" << std::endl;
		}
		catch (std::exception &e){
			std::cout << RED << e.what() << std::endl;
			std::cout << RED"Bureaucrat is still:\n" << intern << reset "\n" << std::endl;
		}
	}
	std::cout << YEL <<"All is well. Nepotism never dies...." reset << std::endl;

}
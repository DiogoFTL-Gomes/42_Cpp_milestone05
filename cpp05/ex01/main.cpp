#include "Bureaucrat.hpp"
#include "Form.hpp"

#define reset "\e[0m"
#define RED "\e[0;31m"
#define YEL "\e[0;33m"

int	main(void){
	//A good form and a bad form
	try{
		Form good("Leave Request", 50, 100);
		Form bad("Bad", 0, 100);
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << reset << std::endl;
	}

	//Insuficient grade to sign
	try{
		Bureaucrat intern("Intern", 150);
		Form topSecret("Top Secret", 50, 100);
		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << reset << std::endl;
	}

	//Big boss signs everything
	try{
		Bureaucrat boss("Boss", 1);
		Form document("Document", 5, 100);
		boss.signForm(document);
		std::cout << document << std::endl;
	}
	catch (std::exception &e){
		std::cout << RED << e.what() << reset << std::endl;
	}

	return (0);
}
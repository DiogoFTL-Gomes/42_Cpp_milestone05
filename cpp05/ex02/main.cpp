#include "Bureaucrat.hpp"
#include "AForm.hpp"
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

int	main(void){
	Bureaucrat	*staff[6] = {0};
	AForm		*folder[11] = {0};

	std::srand(std::time(NULL));

	return (0);
}
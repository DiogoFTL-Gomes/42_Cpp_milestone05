#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include <string>

class Intern {
	private:
		static AForm* createShrubbery(const std::string& target);
		static AForm* createRobotomy(const std::string& target);
		static AForm* createPardon(const std::string& target);

	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};

#endif
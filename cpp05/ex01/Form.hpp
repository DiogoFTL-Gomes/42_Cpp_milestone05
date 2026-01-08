#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_toSignGrade;
		const int			_toExecGrade;

	public:
		Form();
		Form(const std::string &name, int toSign, int toExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//setters
		void	beSigned(const Bureaucrat &bureaucrat);

		//getters
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getToSignGrade() const;
		int					getToExecGrade() const;

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};

};

//operator<< applied on this class
std::ostream	&operator<<(std::ostream &out, const Form &paper);

#endif
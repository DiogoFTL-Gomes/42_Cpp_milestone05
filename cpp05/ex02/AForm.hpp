#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_toSignGrade;
		const int			_toExecGrade;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm();
		AForm(const std::string &name, int toSign, int toExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		//setters
		void	beSigned(const Bureaucrat &bureaucrat);

		//getters
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getToSignGrade() const;
		int					getToExecGrade() const;

		//execution
		void execute(Bureaucrat const &executor) const;

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};
		
		class FormNotSignedException : public std::exception{
			public:
				const char	*what() const throw();
		};
};

//operator<< applied on this class
std::ostream	&operator<<(std::ostream &out, const AForm &paper);

#endif
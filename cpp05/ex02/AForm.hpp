#ifndef AFORM_H
# define AFORM_H

# include <string>
# include <iostream>
# include <exception>

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define reset "\e[0m"

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
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Estagiarino"), _grade(150){
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(150) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

const std::string	&Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(){
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(){
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form){
	try{
		if (form.getIsSigned() == true){
			std::cout << "Form " << form.getName() << " was already signed" << std::endl;
		}
		else{
			form.beSigned(*this);
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
	}
	catch (std::exception &e){
		std::cout << _name << " couldn't sign " 
		<< form.getName() << " because " 
		<< e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &paperPusher){
	out << paperPusher.getName() << ", bureaucrat grade " << paperPusher.getGrade() << ".";
	return out;
}
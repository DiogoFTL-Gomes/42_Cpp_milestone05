#include "Form.hpp"
#include "Bureaucrat.hpp"

static int checkGrade(int grade);

Form::Form() : _name("form_A101"), _isSigned(false), _toSignGrade(150), _toExecGrade(150) {
}

Form::Form(const std::string &name, int toSign, int toExec) 
	: _name(name), _isSigned(false)
	, _toSignGrade(checkGrade(toSign))
	, _toExecGrade(checkGrade(toExec)) {
}

Form &Form::operator=(const Form &other){
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form(){
}

//setters
void	Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_toSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}


//getters
const std::string & Form::getName() const{
	return (this->_name);
}

bool Form::getIsSigned() const{
	return (this->_isSigned);
}

int Form::getToSignGrade() const{
	return (this->_toSignGrade);
}

int Form::getToExecGrade() const{
	return (this->_toExecGrade);
}

//exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

//operator<< applied on this class
std::ostream	&operator<<(std::ostream &out, const Form &paper){
	out << "Form:             " << paper.getName();
	if (paper.getIsSigned() == true)
		out << "\nStatus:           Signed\n";
	else
		out << "\nStatus:           Unsigned\n";
	out << "Grade to sign:    " << paper.getToSignGrade();
	out << "\nGrade to execute: " << paper.getToExecGrade();
	return out;
}

//Does not belong to class
static int	checkGrade(int grade){
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return (grade);
}

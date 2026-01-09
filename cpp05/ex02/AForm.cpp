#include "AForm.hpp"
#include "Bureaucrat.hpp"

static int checkGrade(int grade);

AForm::AForm() : _name("form_A101"), _isSigned(false), _toSignGrade(150), _toExecGrade(150) {
}

AForm::AForm(const std::string &name, int toSign, int toExec) 
	: _name(name), _isSigned(false)
	, _toSignGrade(checkGrade(toSign))
	, _toExecGrade(checkGrade(toExec)) {
}

AForm &AForm::operator=(const AForm &other){
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm(){
}

//setters
void	AForm::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_toSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}


//getters
const std::string & AForm::getName() const{
	return (this->_name);
}

bool AForm::getIsSigned() const{
	return (this->_isSigned);
}

int AForm::getToSignGrade() const{
	return (this->_toSignGrade);
}

int AForm::getToExecGrade() const{
	return (this->_toExecGrade);
}

//exceptions
const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

//operator<< applied on this class
std::ostream	&operator<<(std::ostream &out, const AForm &paper){
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
		throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	return (grade);
}

#include "AForm.hpp"

AForm::~AForm()
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :  name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if  (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(const AForm &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    if (this != &copy)
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "Name and grades are const and can't be overwritten" << std::endl;
	this->isSigned = copy.gradeToSign;
	return *this;
}
void AForm::beSigned(const Bureaucrat &bureaucrat){
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;

}
std::string AForm::getName()
{
	return this->name;
}

bool AForm::getIsSigned()
{
	return this->isSigned;
}

int AForm::getGradeToSign()
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute()
{
	return this->gradeToExecute;
}

#include "Form.hpp"

Form::Form() : name("Default Form"), gradeToSign(150), gradeToExecute(150)
{
	this->isSigned = false;
}

Form::~Form()
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :  name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if  (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->isSigned = false;
}

Form::Form(const Form &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
	if(this != &copy)
		*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << "Just sign copied, other things const." << std::endl;
	this->isSigned = copy.gradeToSign;
	return *this;
}

std::string Form::getName()
{
	return this->name;
}

bool Form::getIsSigned()
{
	return this->isSigned;
}

int Form::getGradeToSign()
{
	return this->gradeToSign;
}

int Form::getGradeToExecute()
{
	return this->gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->gradeToSign)
		throw Form::GradeTooHighException();
	if (bureaucrat.getGrade() > this->gradeToExecute)
		throw Form::GradeTooLowException();
	if (this->isSigned == false)
		this->isSigned = true;
	else
		std::cout << this->name + " is already signed." << std::endl;
}

std::ostream &operator<<(std::ostream &outputGate, const Form &eC) {
	outputGate << eC.getName() << ", form grade to sign " << eC.getGradeToSign() << ", grade to execute" << eC.getGradeToExecute() << std::endl;
	return outputGate;
}

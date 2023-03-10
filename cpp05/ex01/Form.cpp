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

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Name and grades are const and can't be overwritten" << std::endl;
	this->isSigned = other.gradeToSign;
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

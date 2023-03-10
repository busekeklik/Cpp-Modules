#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->isSigned == true)
		throw AForm::AlreadySignedException();
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else
	{
		srand(time(NULL));
		std::cout << "Drilling noises..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Robotomization failed!" << std::endl;
	}
}
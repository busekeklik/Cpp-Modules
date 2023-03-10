#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm *form = new PresidentialPardonForm("Bender");
	Bureaucrat *bureaucrat = new Bureaucrat("Melih", 1);
	bureaucrat->signForm(*form);
	bureaucrat->executeForm(*form);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Piltan", 140);
	AForm *form2 = new RobotomyRequestForm("Miskirik");
	bureaucrat2->signForm(*form2);
	bureaucrat->signForm(*form2);
	bureaucrat2->executeForm(*form2);
	bureaucrat->executeForm(*form2);
	bureaucrat->signForm(*form2);
	Bureaucrat *bureaucrat3 = new Bureaucrat("Cooler Piltan", 2);
	AForm *form3 = new ShrubberyCreationForm("Form");
	bureaucrat3->signForm(*form3);
	bureaucrat3->executeForm(*form3);
	delete bureaucrat3;
	delete form3;
	delete form2;
	delete bureaucrat2;
	delete bureaucrat;
	delete form;
	return 0;
}
// int main()
// {
// 	try{
// 		Bureaucrat bureaucrat("Bob", 1);

// 		ShrubberyCreationForm form("Form");
// 		bureaucrat.signForm(form);
// 		form.execute(bureaucrat);
// 	}
// 	catch(std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return 0;
// }


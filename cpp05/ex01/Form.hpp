#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		Form();
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		std::string getName();
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExecute();
		void beSigned(const Bureaucrat &bureaucrat);
		
		 //exceptions
        class GradeTooHighException :public std::exception{
            public:
                const char *what() const throw(){
                    return "The entered grade is too high.";
                }
        };

        class GradeTooLowException :public std::exception{
            public:
                const char *what() const throw(){
                    return "The entered grade is too low.";
                }
        };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif
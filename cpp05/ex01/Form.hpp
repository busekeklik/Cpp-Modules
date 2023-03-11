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
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
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

std::ostream &operator<<(std::ostream &outputGate, const Form &e);

#endif
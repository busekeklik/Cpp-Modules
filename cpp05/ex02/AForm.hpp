#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
	public:
		virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		std::string getName();
		bool getIsSigned();
		int getGradeToSign();
		int getGradeToExecute();
		//void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) = 0;
		virtual void beSigned(Bureaucrat const &bureaucrat) = 0;

		/*exceptions*/
        class GradeTooHighException :public std::exception
		{
            public:
                virtual const char *what() const throw(){
                    return "The entered grade is too high.";
                }
        };

        class GradeTooLowException :public std::exception
		{
            public:
                virtual const char *what() const throw(){
                    return "The entered grade is too low.";
                }
        };
        class AlreadySignedException: public std::exception
		{
			public:
				virtual const char *what() const throw(){
                    return "Form is already signed.";
                }
		};
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif
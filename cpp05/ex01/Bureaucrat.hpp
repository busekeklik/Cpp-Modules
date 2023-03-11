#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        Bureaucrat(const std::string &name, int grade);
        const std::string &getName() const;

        //functions
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &outputGate, const Bureaucrat &entryClass);

#endif
#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		// Constructors
		AForm(const std::string name, const int signed_grade, const int executed_grade);
		AForm(const AForm &copy);

		// Destructor
		virtual ~AForm();

		// Operator
		AForm& operator=(const AForm &assign);

		
}
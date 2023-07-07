#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
	public:
		// constructor
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);

		// Destructor
		~Bureaucrat();

		// Operators
		Bureaucrat &operator=(const Bureaucrat &assign);

		// Getters & Setters
		const std::string getName() const;
		int getGrade() const;

		//Exceptions
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
		class NameRequiredException : public std::exception {
			virtual const char* what() const throw();
		};

		void increaseGrade();
		void decreaseGrade();

	private:
		Bureaucrat();

		const std::string _name;
		int _grade;
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif
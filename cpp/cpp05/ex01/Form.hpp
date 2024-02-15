#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		// 생성자
		Form(const std::string name, const int signed_grade, const int executed_grade);

		// 복사 생성자
		Form(const Form &copy);

		// 소멸자
		~Form();

		// 대입 연산자 오버로드
		Form& operator=(const Form &assign);

		// Getters
		const std::string getName() const;
		bool getSigned() const;
		int getSignedGrade() const;
		int getExecutedGrade() const;

		// 예외 클래스
		/**
		 * @brief 등급(grade)이 너무 높을 때 예외 발생
		 * 	1등급이 최상
		 */
		class GradeTooHighException : public std::exception {
			 const char* what() const throw();
		};

		/**
		 * @brief 등급(grade)이 너무 낮을 때 예외 발생
		 * 150등급이 최하
		 */
		class GradeTooLowException : public std::exception {
			 const char* what() const throw();
		};

		/**
		 * @brief 이름(name)이 없을 때 예외 발생
		 */
		class NoNameException : public std::exception {
			 const char* what() const throw();
		};

		/**
		 * @brief 이미 sign을 했을 경우 예외 발생
		 */
		class AlreadySignedException : public std::exception {
			 const char* what() const throw();
		};

		/**
		 * @brief sign한다.
		 * sign을 하기 전에 이름이 없거나 등급이 너무 낮을 경우 예외 발생
		 * 
		 * @param bureaucrat 점수를 확인할 Bureaucrat 인스턴스
		 */
		void signForm(const Bureaucrat& bureaucrat);

	private:
		Form();
		
		const std::string _name;
		bool _is_signed;
		const int _signed_grade;
		const int _executed_grade;
};

// Stream operators
std::ostream& operator<<(std::ostream &stream, const Form &object);

#endif
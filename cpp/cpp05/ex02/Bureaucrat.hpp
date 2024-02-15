#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		// 생성자
		Bureaucrat(const std::string name, int grade);

		// 복사 생서자
		Bureaucrat(const Bureaucrat &copy);

		// 소멸자
		~Bureaucrat();

		// 대입연산자 오버로드
		Bureaucrat &operator=(const Bureaucrat &assign);

		// Getters
		const std::string getName() const;
		int getGrade() const;

		// 예외 클래스 정의
		// 보통 예외 클래스들은 std::exception을 상속하여 작성한다. 
		/**
		 * @brief 등급(grade)이 너무 높을 때 예외 발생
		 * 	1등급이 최상
		 */
		class GradeTooHighException : public std::exception {

			// what() 함수는 예외에 대한 설명을 문자열로 반환
			// throw()를 사용하면 해당 함수가 어떠한 예외를 던지지 않을 것이라고 정보를 제공
			// 실제로 보장하지는 않는다.
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
		 * @brief 등급(grade)을 증가시킨다.
		 * 숫자가 낮을수록 등급이 높은 것
		 */
		void increaseGrade();

		/**
		 * @brief 등급(grade)을 감소시킨다.
		 * 숫자가 높을수록 등급이 낮은 것
		 */
		void decreaseGrade();

		/**
		 * @brief form에 sign한다.
		 * Form 클래스의 beSigned 함수를 사용하여 sign하기에 적절한지 확인한다.
		 * 점수가 너무 낮거나, 이름이 없다면 예외가 발생한다.
		 * @param form sign을 할 form
		 */
		void signForm(AForm &form);

		/**
		 * @brief form을 시행한다.
		 * 
		 * @param form 시행할 from 인스턴스
		 */
		void executeForm(AForm const & form);

	private:
		Bureaucrat();
		const std::string _name;
		int _grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif
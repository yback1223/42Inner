#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		// 생성자
		AForm(const std::string name, const int signed_grade, const int executed_grade);
		
		// 복사 생성자
		AForm(const AForm &copy);
		
		// 소멸자
		virtual ~AForm();
		
		// 대입 연산자 오버로드
		AForm & operator=(const AForm &assign);
		
		// Getters
		const std::string getName() const;
		bool getSinged() const;
		int getSignedGrade() const;
		int getExecutedGrade() const;
		
		// 예외 클래스 정의
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
		 * @brief form에 sign이 되어있지 않을 경우 예외 발생
		 */
		class NotSignedException : public std::exception {
			const char* what() const throw();
		};

		/**
		 * @brief 이미 sign을 했을 경우 예외 발생
		 */
		class AlreadySignedException : public std::exception {
			const char* what() const throw();
		};

		/**
		 * @brief form에 sign을 한다.
		 * 
		 * @param bureaucrat sign을 할 인스턴스
		 */
		void beSigned(const Bureaucrat & bureaucrat);
		
		/**
		 * @brief sign을 할 수 있는지 확인
		 * 추상 메서드로 선언
		 * 
		 * @param executor sign을 진행할 bureaucrat 인스턴스
		 */
		virtual void execute(Bureaucrat const & executor) const = 0;

	protected:
		bool eligible(Bureaucrat const & executor) const;

	private:
		AForm();
		const std::string _name;
		bool _is_singed;
		const int _signed_grade;
		const int _executed_grade;
		
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const AForm &object);

#endif
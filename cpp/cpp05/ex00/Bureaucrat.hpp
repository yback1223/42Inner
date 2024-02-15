#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

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
		 * @brief 등급(grade)을 증가시킨다.
		 * 숫자가 낮을수록 등급이 높은 것
		 */
		void increaseGrade();

		/**
		 * @brief 등급(grade)을 감소시킨다.
		 * 숫자가 높을수록 등급이 낮은 것
		 */
		void decreaseGrade();

	private:
		Bureaucrat();

		const std::string _name;
		int _grade;
};

// Stream operators
std::ostream & operator<<(std::ostream &stream, const Bureaucrat &object);

#endif
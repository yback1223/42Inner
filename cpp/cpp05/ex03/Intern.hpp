#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern {
	public:
		// 생성자
		Intern();

		// 복사 생성자
		Intern(const Intern &copy);
		
		// 소멸자
		~Intern();
		
		// 대입 연산자 오버라이드
		Intern & operator=(const Intern &assign);
		
		// 예외 클래스
		/**
		 * @brief 존재하지 않는 form일 경우 예외 발생
		 */
		class NoSuchFormException : public std::exception {
			 const char* what() const throw();
		};

		/**
		 * @brief 만들 수 있는 form일 경우, 생성하여 반환
		 * 
		 * @param form form 타입
		 * @param target form의 이름으로 지정할 것
		 * @return AForm* 생성된 form 인스턴스 반환
		 */
		AForm * makeForm(std::string form, std::string target) const;
	private:
		
};

#endif
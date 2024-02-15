#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm: public virtual AForm {
	public:
		// 생성자
		ShrubberyCreationForm(std::string target);

		// 복사 생성자
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		// 소멸자
		virtual ~ShrubberyCreationForm();
		
		// 대입 연산자 오버로드
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		// 예외 클래스

		/**
		 * @brief 파일 생성에 실패하면 예외 발생
		 */
		class UnplantableException : public std::exception {
			virtual const char* what() const throw();
		};

		void execute(Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm();
		std::string _target;
};

#endif
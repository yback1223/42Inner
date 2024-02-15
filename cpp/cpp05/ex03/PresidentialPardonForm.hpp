#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public virtual AForm
{
	public:
		// 생성자
		PresidentialPardonForm(std::string target);

		// 복사 생성자
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		// 소멸자
		virtual ~PresidentialPardonForm();
		
		// 대입 연산자 오버로드
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		void execute(Bureaucrat const & executor) const;

	private:
		PresidentialPardonForm();
		std::string _target;
};

#endif
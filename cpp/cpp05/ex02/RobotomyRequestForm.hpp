#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm: public virtual AForm {
	public:
		// 생성자
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// 소멸자
		virtual ~RobotomyRequestForm();
		
		// 대입 연산자 오버로드
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
		void execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm();
		bool successful() const;

		std::string _target;	
};

#endif
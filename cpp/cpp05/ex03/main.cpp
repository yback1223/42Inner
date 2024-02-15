#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern	someRandomIntern;
    	AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		// RobotomyRequestForm* robotomyForm = dynamic_cast<RobotomyRequestForm*>(rrf);
        // if (robotomyForm != nullptr) {
        //     std::cout << robotomyForm->getTarget() << "\n";
        // }
		delete rrf;
		rrf = someRandomIntern.makeForm("wrong form", "hep");
		delete rrf;
	} catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}
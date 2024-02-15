#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat a("a", 3);
	ShrubberyCreationForm scf("scf");
	RobotomyRequestForm rrf("rrf");
	PresidentialPardonForm ppf("ppf");
	Bureaucrat b("b", 65);

	try {
		a.signForm(scf);
		a.executeForm(scf);

		b.signForm(rrf);
		a.executeForm(rrf);

		a.signForm(ppf);
		a.executeForm(ppf);

		a.signForm(rrf);
		b.signForm(rrf);
		b.executeForm(rrf);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
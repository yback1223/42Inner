#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat_A("A", 75);
		Bureaucrat bureaucrat_B("B", 80);
		Form form_X("x_contract", 80, 80);
		Form form_Y("y_contract", 75, 75);

		bureaucrat_A.signForm(form_X);
		std::cout << bureaucrat_A;
		std::cout << form_X << std::endl;

		bureaucrat_B.signForm(form_Y);
		std::cout << bureaucrat_B;
		std::cout << form_Y << std::endl;

		bureaucrat_A.signForm(form_X);
		std::cout << bureaucrat_A;
		std::cout << form_X << std::endl;;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
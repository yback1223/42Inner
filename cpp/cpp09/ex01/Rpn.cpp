#include "Rpn.hpp"

#include <sstream>
#include <iostream>

// 생성자
Rpn::Rpn(std::string expr)
{
	std::stringstream ss(expr);
	char op;

	ss >> op;
	if (ss.fail()) throw WrongToken();
	if (op < '0' || op > '9') throw WrongToken();
	stack.push(op - '0');
	while (ss >> op) {
		if (ss.fail()) throw WrongToken();
		if (op >= '0' && op <= '9') stack.push(op - '0');
		else if (op == '+') {
			if (stack.size() < 2) throw WrongToken();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b + a);
		} else if (op == '-') {
			if (stack.size() < 2) throw WrongToken();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b - a);
		} else if (op == '*') {
			if (stack.size() < 2) throw WrongToken();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b * a);
		} else if (op == '/') {
			if (stack.size() < 2) throw WrongToken();
			double a = stack.top();
			if (a == 0.0) throw DividedZero();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b / a);
		} else throw WrongToken();
	}
}

// 소멸자
Rpn::~Rpn() {}

double Rpn::calc() {
	if (stack.size() != 1) throw WrongToken();
    return stack.top();
}

// 예외 what() 구현
const char * Rpn::WrongToken::what() const throw() {
	return "Error";
}

const char *Rpn::DividedZero::what() const throw() {
    return "Error";
}

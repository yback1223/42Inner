//
// Created by Yong Min Back on 2023/04/25.
//

#include "Account.hpp"
#include <iostream>
#include <ctime> // time()

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += _amount;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp() {
	time_t timeStamp;
	char buff[16];

	time(&timeStamp);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&timeStamp));
	std::cout << "[" << buff << "]";
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount;

	p_amount = _amount;
	_amount += deposit;
	_displayTimestamp();
	_nbDeposits++;
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount" << p_amount << ";";
	std::cout << "deposits:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount;

	p_amount = _amount;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (_amount >= 0) {
		_nbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	} else {
		std::cout << "withdrawal:refused" << std::endl;
		_amount = p_amount;
		return (false);
	}
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:40:05 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:46:17 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts		 = 0;
int Account::_totalAmount		 = 0;
int Account::_totalNbDeposits	 = 0;
int Account::_totalNbWithdrawals = 0;

// ?format: YYYYMMDD_HHMMSS
void Account::_displayTimestamp(void)
{
	std::time_t t  = std::time(0);
	std::tm	   *lt = std::localtime(&t);
	std::cout << '[' << (lt->tm_year + 1900) << std::setw(2)
			  << std::setfill('0') << (lt->tm_mon + 1) << std::setw(2)
			  << std::setfill('0') << lt->tm_mday << '_' << std::setw(2)
			  << std::setfill('0') << lt->tm_hour << std::setw(2)
			  << std::setfill('0') << lt->tm_min << std::setw(2)
			  << std::setfill('0') << lt->tm_sec << "] ";
}

// *Statics
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
// getters
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

// Constructors

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
	  _nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
			  << std::endl;
}

// Not used but required by header
Account::Account(void)
	: _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	++_nbDeposits;

	_totalAmount += deposit;
	++_totalNbDeposits;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
			  << ";deposit:" << deposit << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount;

	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	++_nbWithdrawals;

	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;

	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

// Not used but required by header
int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

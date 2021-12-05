#include "Fraction.h"
#include <iostream>
#include <stdexcept>

long gcd(long m_numerator, long m_denominator) {
	m_numerator = abs(m_numerator);
	while (m_numerator && m_denominator) {
		if (m_numerator > m_denominator) {
			m_numerator %= m_denominator;
		}
		else {
			m_denominator %= m_numerator;
		}
	}
	return m_numerator + m_denominator;
	// Вычисляет наибольший общий делитель по // алгоритму Евклида //
}
void fraction::set() {
	if (denominator < 0) {
		denominator = abs(denominator);
		numerator *= -1;
	}
	if (numerator == 0) {
		denominator = 1;
	}
	long m_gcd = gcd(numerator, denominator);
	numerator /= m_gcd;
	denominator /= m_gcd;
}
fraction::fraction(long m_numerator, long m_denominator) {
	numerator = m_numerator;
	denominator = m_denominator;
	set();
}

void fraction::check() {
	if (denominator == 0) {
		throw std::overflow_error("denominator is zero");
	}
}

void fraction::setNumerator(long m_numerator) {
	numerator = m_numerator;
	set();
}
long fraction::getNumerator() {
	return numerator;
}

void fraction::setDenominator(long m_denominator) {
	denominator = m_denominator;
	set();
}
long fraction::getDenominator() {
	return denominator;
}

double fraction::getDouble() {
	return static_cast<double>(numerator) / denominator;
}
void fraction::print() {
	if (denominator != 1) {
		std::cout << numerator << "/" << denominator;
	}
	else
		std::cout << numerator;
}
fraction fraction::operator * (fraction  secondfraction) {
	long  comp_numerator = numerator * secondfraction.numerator;
	long  comp_denominator = denominator * secondfraction.denominator;
	return fraction(comp_numerator, comp_denominator);
}
fraction fraction::operator + (fraction  secondfraction) {
	long addition_num = numerator * secondfraction.denominator + secondfraction.numerator * denominator;
	long addition_den = denominator * secondfraction.denominator;
	return fraction(addition_num, addition_den);
}
fraction fraction::operator - (fraction  secondfraction) {
	long difference_num = numerator * secondfraction.denominator - secondfraction.numerator * denominator;
	long difference_den = denominator * secondfraction.denominator;
	return fraction(difference_num, difference_den);
}
fraction fraction::operator / (fraction  secondfraction) {
	if (secondfraction.numerator != 0) {
		long divisor_num = numerator * secondfraction.denominator;
		long divisor_den = denominator * secondfraction.numerator;
		return fraction(divisor_num, divisor_den);
	}
} 
fraction fraction::operator * (long a) {
	long comp_numerator = numerator * a;
	return fraction(comp_numerator, denominator);
}
fraction fraction::operator + (long a) {
	long addition_num = numerator + a * denominator;

	return fraction(addition_num, denominator);
}
fraction fraction::operator - (long a) {
	long difference_num = numerator - a * denominator;
	return fraction(difference_num, denominator);
}
fraction fraction::operator / (long a) {
	if (a != 0) {
		long divisor_dem = denominator * a;
		return fraction(numerator, divisor_dem);
	}
}
fraction fraction::operator - () {
	long change_num = numerator * (-1);
	return fraction(change_num, denominator);
}
bool fraction::operator > (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator > secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator < (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator < secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator >= (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator >= secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator <= (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator <= secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator == (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator == secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator != (fraction secondfraction) {
	if (static_cast<double>(numerator) / denominator != secondfraction.getDouble())
		return true;
	else
	return false;
}
bool fraction::operator > (long a) {
	if (static_cast<double>(numerator) / denominator > a)
		return true;
	else
	return false;
}
bool fraction::operator < (long a) {
	if (static_cast<double>(numerator) / denominator < a)
		return true;
	else
	return false;
}
bool fraction::operator >= (long a) {
	if (static_cast<double>(numerator) / denominator >= a)
		return true;
	else
	return false;
}
bool fraction::operator <= (long a) {
	if (static_cast<double>(numerator) / denominator <= a)
		return true;
	else
	return false;
}
bool fraction::operator == (long a) {
	if (static_cast<double>(numerator) / denominator == a)
		return true;
	else
	return false;
}
bool fraction::operator != (long a) {
	if (static_cast<double>(numerator) / denominator != a)
		return true;
	else
	return false;
}


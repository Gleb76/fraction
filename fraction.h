#include<iostream>
#pragma once

class fraction {
private:
	long numerator;
	long denominator;
	void set();
public:
	void set(long m_numerator, long m_denominator);
	fraction(long = 1, long = 1);
	void setNumerator(long);
	long getNumerator();
	void setDenominator(long);
	long getDenominator();
	void check();
	fraction operator * (fraction);
	fraction operator + (fraction);
	fraction operator - (fraction);
	fraction operator / (fraction);
	fraction operator * (long);
	fraction operator + (long);
	fraction operator - (long);
	fraction operator / (long);
	fraction operator - ();
	bool operator > (fraction);
	bool operator < (fraction);
	bool operator >= (fraction);
	bool operator <= (fraction);
	bool operator == (fraction);
	bool operator != (fraction);
	bool operator > (long);
	bool operator < (long);
	bool operator >= (long);
	bool operator <= (long);
	bool operator == (long);
	bool operator != (long);
	void print();
	double getDouble();

};

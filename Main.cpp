#include "fraction.h"
#include<iostream>
#include <stdexcept>
void print_operations(fraction firstfraction, fraction secondfraction, fraction operation, char sign) {
	firstfraction.print();
	std::cout << " " << sign << " ";
	secondfraction.print();
	std::cout << " = ";
	operation.print();
	std::cout << std::endl;
}
void print_comparisons(fraction firstfraction, fraction secondfraction, bool comparison, char sign, char sign2) {
	firstfraction.print();
	std::cout << " " << sign << sign2 << " ";
	secondfraction.print();
	if (comparison) {
		std::cout << " -- " << "true\n";
	}
	else {
		std::cout << " -- " << "false\n";
	}
}
void test_operations(fraction firstfraction, fraction secondfraction) {
	fraction composition = firstfraction * secondfraction;
	print_operations(firstfraction, secondfraction, composition, '*');
	fraction addition = firstfraction + secondfraction;
	print_operations(firstfraction, secondfraction, addition, '+');
	fraction difference = firstfraction - secondfraction;
	print_operations(firstfraction, secondfraction, difference, '-');
	fraction divisor = firstfraction / secondfraction;
	if (secondfraction.getNumerator() != 0) {
		print_operations(firstfraction, secondfraction, divisor, '/');
	}
	else std::cout << "Error\n";
	bool comp = firstfraction > secondfraction;
	print_comparisons(firstfraction, secondfraction, comp, '>', ' ');
	bool comp2 = firstfraction < secondfraction;
	print_comparisons(firstfraction, secondfraction, comp2, '<', ' ');
	bool comp3 = firstfraction >= secondfraction;
	print_comparisons(firstfraction, secondfraction, comp3, '>', '=');
	bool comp4 = firstfraction <= secondfraction;
	print_comparisons(firstfraction, secondfraction, comp4, '<', '=');
	bool comp5 = firstfraction == secondfraction;
	print_comparisons(firstfraction, secondfraction, comp5, '=', '=');
	bool comp6 = firstfraction != secondfraction;
	print_comparisons(firstfraction, secondfraction, comp6, '!', '=');
}
void print_operations(fraction firstfraction, long a, fraction operation, char sign) {
	firstfraction.print();
	std::cout << " " << sign << " " << a << " = ";
	operation.print();
	std::cout << std::endl;
}
void print_comparisons(fraction firstfraction, long a, bool comparison, char sign, char sign2) {
	firstfraction.print();
	std::cout << " " << sign << sign2 << " " << a;
	if (comparison) {
		std::cout << " -- " << "true\n";
	}
	else {
		std::cout << " -- " << "false\n";
	}
}
void test_getDouble(fraction firstfraction, fraction secondfraction) {
	std::cout << "firstfraction.getDouble() = " << firstfraction.getDouble() << std::endl;
	std::cout << "secondfraction.getDouble() = " << secondfraction.getDouble() << std::endl;
}
void change_the_sign(fraction firstfraction) {
	fraction change_sign = -firstfraction;
	firstfraction.print();
	std::cout << " = ";
	change_sign.print();
	std::cout << std::endl;
}
int main() {
	setlocale(LC_ALL, "ru");
	long x, y;
	std::cout << "¬ведите числитель\n";
	std::cin >> x;
	std::cout << "¬ведите знаменатель\n";
	std::cin >> y;
	fraction firstfraction(x, y);

	try {
		firstfraction.check();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	long b, c;
	std::cout << "¬ведите числитель\n";
	std::cin >> b;
	std::cout << "¬ведите знаменатель\n";
	std::cin >> c;
	fraction secondfraction(b, c);

	try {
		secondfraction.check();
	}
	catch (std::exception& c) {
		std::cout << c.what() << std::endl;
		return 1;
	}
	test_operations(firstfraction, secondfraction);
	test_getDouble(firstfraction, secondfraction);
	change_the_sign(firstfraction);
	return 0;
}
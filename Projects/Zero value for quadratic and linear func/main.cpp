								// ****************************************************************	//
								//   Calculate zero value for quadratic and linear functions   	    //
								//																	//
								// This programm calculates the x-values where the graph cuts		//
								// the x-axis.														//
								// Made for following kinds of functions:							//
								// - y = x^2 + px + q												//
								// - y = mx + b														//
								// 																	//
								// Author: Deniel           										//
								// Programmed on C++												//
								// **************************************************************** //

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <conio.h>
#define DEBUG

#ifdef DEBUG
void TestCases();
void testCase_calculate_zero_value_for_q_func();
void testCase_calculate_zero_value_for_linear_func();
#endif

// ******** Main calculation ******** //
double calculate_zero_value_for_linear_func(double m, double b) {
	if (m == 0 && b != 0) { // the case where the graph does not cut with the horizontal axis
		return std::numeric_limits<double>::quiet_NaN(); // NaN - Not a number
	}
	else if (m == 0) { // the case where the graph is at the horizontal axis
		return 0;
	}

	return -b / m;
}

std::vector<double> calculate_zero_value_for_q_func(double p, double q) {
	double x1{0};
	double x2{0};
	double D = (p / 2) * (p / 2) - q;

	if (D < 0) // No possible results
		return std::vector<double>{};

	x1 = -p / 2 + sqrt(D);
	x2 = -p / 2 - sqrt(D);

	return (D == 0) ? std::vector<double>{x1} : std::vector<double>{ x1, x2 };
}

// ******** Start menu ******** //
void render_choice_message(const char* text, short pos, short opt) { 
	if (pos == opt)
		std::cout << "-->\t\033[30;47m";
	else
		std::cout << "\t";
	std::cout << text << "\033[0m" << std::endl;
}

void changeOpt(char key, short& opt) {
	if (key == 72)	// When up-arrow
		opt--;
	else if (key == 80)	// When down-arrow 
		opt++;
}

void limitOpt(short& opt, short min, short max) {
	if (opt < min)
		opt = max;
	else if (opt > max)
		opt = min;
}

short choose_option_menu() {
	short opt{0};
	char key1{0};	// needed to process the pressed button
	char key2{0};

	while (true) {
		std::cout << "Use up/down arrows to choose\tPress ENTER to confirm choice" << std::endl << std::endl;
		std::cout << "Choose the correct kind of function that the x value(s) should be calculated for" << std::endl << std::endl;

		// printing the choice variants
		render_choice_message("y = x^2 + px + q", 0, opt); // prints the offered choice with an arrow when choosen
		render_choice_message("y = mx + b", 1, opt);
		std::cout << std::endl;
		render_choice_message("Exit", 2, opt);

		// reading the pressed key  // FOR INFO: When an arrow gets pressed, there will be two keys in the buffer, not one!
		key1 = _getch();
		std::cout << "\033[2J\033[1;1H"; // Instead of system("cls"); because this variant is more crossplatform
		if (key1 == 13) // If the key is Enter, that chas the ASCII code 13
			return opt;
		else if (key1 != -32) // If the key is not an arrow
			continue;
		key2 = _getch(); // If an arrow has been pressed, the second value will be catched here

		changeOpt(key2, opt); // Changing the currently selected option depending on the pressed arrow
		limitOpt(opt, 0, 2); // Changing the value of opt, if it is out of the range
	}
}

// ******** Process part ******** //
void process_linear_func() {
	double m{0};
	double b{0};

	std::cout << "y = mx + b" << std::endl << std::endl;

	std::cout << "Type the value for m: ";
	std::cin >> m;
	std::cout << "Type the value for b: ";
	std::cin >> b;
	std::cout << std::endl;

	// This block should print the expression "For y = mx + b" with correct sign for b
	std::cout << "For y = " << m << 'x';
	if (b < 0)
		std::cout << " - " << abs(b);
	else
		std::cout << " + " << b;
	std::cout << std::endl;

	// Printing the result
	double res = calculate_zero_value_for_linear_func(m, b);
	if (std::isnan(res))
		std::cout << "There is no result." << std::endl << std::endl;
	else
		std::cout << "The result is:x = " << res << std::endl << std::endl;
	
	std::cout << "Press any button to continue..." << std::endl;
	char tmp_key = _getch();
}

void process_quadrat_func() {
	double p{0};
	double q{0};

	std::cout << "y = x^2 + px + q" << std::endl << std::endl;

	std::cout << "Type the value for p: ";
	std::cin >> p;
	std::cout << "Type the value for q: ";
	std::cin >> q;
	std::cout << std::endl;

	// This block should print the expression "For y = x^2 + px + q" with correct sign for p and q
	std::cout << "For y = x^2";	
	if (p < 0)
		std::cout << " - " << abs(p);
	else
		std::cout << " + " << p;
	std::cout << 'x';
	if (q < 0)
		std::cout << " - " << abs(q);
	else
		std::cout << " + " << q;
	std::cout << std::endl;

	// Printing the result
	std::vector<double> res = calculate_zero_value_for_q_func(p, q);
	if (res.size() == 0)
		std::cout << "There is no result." << std::endl << std::endl;
	else if (res.size() == 1)
		std::cout << "The result is: x = " << res[0] << std::endl << std::endl;
	else
		std::cout << "The results are: x1 = " << res[0] << "; x2 = " << res[1] << std::endl << std::endl;

	std::cout << "Press any button to continue..." << std::endl;
	char tmp_key = _getch();
}

void process_option(short opt) {
	switch (opt) {
	case 0:
		process_quadrat_func();
		break;
	case 1:
		process_linear_func();
		break;
	}
	std::cout << "\033[2J\033[1;1H";
}

int main() {
#ifdef DEBUG
	TestCases();
#endif

	short opt{0}; // saves the choosen option that will be used in process

	while (true) {
		opt = choose_option_menu();
		if (opt == 2)	// If exit was choosen
			return 0;
		process_option(opt);
	}
}


// *************** Test cases **************** //
#ifdef DEBUG 
void TestCases() {
	std::cout << "\033[33m# ********** Started TestCases *********\033[0m" << std::endl;
	
	std::cout << "\033[32m# *\tTesting calculate_zero_value_for_q_func\033[0m" << std::endl;
	testCase_calculate_zero_value_for_q_func();
	std::cout << "\033[32m# **\tTesting calculate_zero_value_for_linear_func\033[0m" << std::endl;
	testCase_calculate_zero_value_for_linear_func;

	std::cout << "\033[33m# ********** Finished TestCases *********\033[0m" << std::endl << std::endl;
}

void testCase_calculate_zero_value_for_q_func() {
	auto tmp = calculate_zero_value_for_q_func(3, -4);
	assert(tmp[0] == 1 && tmp[1] == -4);
	
	tmp = calculate_zero_value_for_q_func(2, 1);
	assert(tmp[0] == -1);

	tmp = calculate_zero_value_for_q_func(1, 4);
	assert(tmp.size() == 0);
	
	tmp = calculate_zero_value_for_q_func(0, -9);
	assert(tmp[0] == 3 && tmp[1] == -3);

	tmp = calculate_zero_value_for_q_func(0, 0);
	assert(tmp[0] == 0);

	tmp = calculate_zero_value_for_q_func(-5, 6);
	assert(tmp[0] == 3 && tmp[1] == 2);
}

void testCase_calculate_zero_value_for_linear_func() {
	assert(calculate_zero_value_for_linear_func(2, 4) == -2);
	assert(calculate_zero_value_for_linear_func(-3, 6) == 2);
	assert(calculate_zero_value_for_linear_func(0, 0) == 0);
	assert(calculate_zero_value_for_linear_func(1, 0) == 0);
	assert(calculate_zero_value_for_linear_func(0.5, 1.5) == -3);
	assert(calculate_zero_value_for_linear_func(1000000, 5000000) == -5);
	assert(std::isnan(calculate_zero_value_for_linear_func(0, 1)));
}
#endif
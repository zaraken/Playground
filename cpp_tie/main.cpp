#include <iostream>
#include <vector>
#include <tuple>
#include <string>

#include "TieN1.h"
#include "TieN2.h"

int main() {
	int wait;

	int a = 11, b = 12;
	double c = 13.1;
	string d = "14";
	tieN1(a, b, c, d) = make_tuple(1, 2, 3.1, "4");
	// tieN2(a, std::ignore, c, d) = make_tuple(1, 2, 3.1, "4");
	// tuple<int&, int&, double&, string&>(a, b, c, d) = make_tuple(1, 2, 3.1, "4");
	cout << a << " " << b << " " << c << " " << d << endl;
	
	std::cin >> wait;
}

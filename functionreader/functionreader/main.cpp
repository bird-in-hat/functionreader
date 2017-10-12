#include <cstdlib>
#include <iostream>
#include <string>

#include "fparser.hh"
#include "optlib.h"

using namespace std;

void menu(FunctionParser fparser){
	int choice = 1;
	double a = 0.2, b = 3.4;
	double eps, r = 2.4;
	double x;
	cout << "Enter left and right borders:";
	cin >> a >> b;
	eps = (b - a)*0.0001;
	cout << "Epsilon = " << eps << endl;
	cout << "Reliability = " << r << endl;
	int n;

	x = agp(fparser, a, b, r, eps, n);
	cout << "AGP      : x = " << x << " in " << n << " iterations\n";
	x = piyavskiy(fparser, a, b, r, eps, n);
	cout << "Piyavskiy: x = " << x << " in " << n << " iterations\n";
	x = kushner(fparser, a, b, eps, n); // Выбрать параметр
	cout << "Kushner  : x = " << x << " in " << n << " iterations\n";

	/*while (choice){
		
		cout << "1 - AGP\n2 - Piyavskiy\n3 - Kushner\n\n0 - Exit\n>";
		cin >> choice;
		switch (choice)
		{
			case 1:
				x = agp(fparser, a, b, r, eps, n);
				break;
			case 2:
				x = piyavskiy(fparser, a, b, r, eps, n);
				break;
			case 3:
				x = kushner(fparser, a, b, eps, n);
				break;
			case 0:
				return;
		}
		cout << "Result: x = " << x << " in " << n << " iterations\n";
	}*/
}

int main(){
	std::string function;
	FunctionParser fparser;

	fparser.AddConstant("pi", 3.1415926535897932);
	while (true)
	{
		std::cout << "Enter function f(x): ";
		std::getline(std::cin, function);
		if (std::cin.fail()) return -1;

		int res = fparser.Parse(function, "x");
		if (res < 0) break;

		std::cout << std::string(res + 7, ' ') << "^\n"
			<< fparser.ErrorMsg() << "\n\n";
	}
	if (std::cin.fail()) return -1;

	menu(fparser);

	return 0;

}
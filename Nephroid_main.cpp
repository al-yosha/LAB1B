#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <iomanip>
#include "Nephroid.h"

int main() {
	lab1b::Nephroid c;
	lab1b::Point p;
	int fl1 = 1;
	double r;
	std::string s;
	
	while (fl1) {
		std::cout << "Nephroid's equation is: " << std::endl;
		s = c.equation();
		std::cout << s;
		std::cout << "area: " << c.area() << std::endl;
		std::cout << "perimeter: " << c.length() << std::endl;
		int fl2 = 1;
		while (fl2) {
			std::cout << "Enter t to calculate the radius of curvature and coordinatses or press ctrl+Z to quit:" << std::endl;
			double t;
			lab1b::Point cords;
			std::cin >> t;
			fl2 = std::cin.good();
			if (!fl2)
				continue;
			try {
				std::cout << "Radius of curvature: " << std::setprecision(4) << c.curveradius(t) << std::endl;
				cords = c.coordinates(t);
				std::cout << "Coordinates: " << "x = " << cords.x << ", y = " << cords.y << std::endl;
			}
				catch (std::exception & ex)
			{
				std::cout << ex.what() << std::endl;
			}
		}
		std::cin.clear();
		std::cout << "Enter new x, y and r to continue or press ctrl+Z to quit:" << std::endl;
		std::cin >> p.x >> p.y >> r;
		if (std::cin.good()) {
			c.setP(p);
			try {
				c.setR(r);
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << std::endl;
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				continue;
			}
		}
		else {
			std::cout << "Incorrect input detected, the program will close";
			fl1 = 0;
		}
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
	return 0;
}
#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Nephroid.h"
#include <string>

namespace lab1b {
	Nephroid& Nephroid::setR(double r0) {
		if (r0 <= 0)
			throw std::exception("Invalid radius");
		r = r0;
		return *this;
	}

	Nephroid::Nephroid(double rad) : p(0, 0) {
		if (rad <= 0)
			throw std::exception("Invalid radius");
		r = rad;
	}

	Nephroid::Nephroid(const Point &p0, double rad) : p(p0) {
		if (rad <= 0)
			throw std::exception("Invalid radius");
		r = rad;
	}

	Nephroid::Nephroid(double x0, double y0, double rad) : p(x0, y0)  {
		if (rad <= 0)
			throw std::exception("Invalid radius");
		r = rad;
	}

	Point Nephroid::coordinates(double t) const {
		Point cords;
		cords.x = p.x + 3 * r * cos(t) - r * cos(3 * t);
		cords.y = p.y + 3 * r * sin(t) - r * sin(3 * t);
		return cords;
	}

	Nephroid& Nephroid::setP(Point& p0) { 
		p = p0; 
		return *this; 
	};

	Point Nephroid::getP() const { 
		return p; 
	};

	double Nephroid::getR() const { 
		return r; 
	};

	double Nephroid::length() const { 
		return 24 * r; 
	};

	double Nephroid::curveradius(double t) const { 
		return abs(3 * r * sin(t)); 
	};

	double Nephroid::area() const { 
		return 12 * 3.1415 * r * r; 
	};

	std::string Nephroid::equation() const {
		//const char* s1 = "((x - )^2 + (y - )^2 - )^3 = *(x - )^2\n";
		std::string s1;
		if (p.x == 0)
			s1 += "(x^2";
		else
			s1 += "((x - " + std::to_string(p.x) + ")^2";
		if (p.y == 0)
			s1 += " + y^2";
		else
			s1 += " + (y - " + std::to_string(p.y) + ")^2";
		s1 += " - " + std::to_string(4 * r * r) + ")^3 = " + std::to_string(108 * r * r * r * r) + "*";
		if (p.x == 0)
			s1 += "x^2\n";
		else
			s1 += "(x - "+ std::to_string(p.x) + ")^2\n";
		return s1;
	}

}
#include <strstream>
#include <stdio.h>
#include <string.h>
#include "Nephroid.h"

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

	double Nephroid::curveradius(double t = 0) const { 
		return abs(3 * r * sin(t)); 
	};

	double Nephroid::area() const { 
		return 12 * 3.1415 * r * r; 
	};

	char* Nephroid::equation() const {
		const char* s1 = "((x - )^2 + (y - )^2 - )^3 = *(x - )^2\n";
		int l = strlen(s1) + 1;
		char num[20];
		sprintf_s(num, 20, "%.2f", p.x);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.x);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", p.y);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", 4 * r * r);
		l += strlen(num);
		sprintf_s(num, 20, "%.2f", 108 * r * r * r * r);
		l += strlen(num);
		char* s = new char[l];
		if (p.x == 0)
			sprintf_s(s, l, "(x^2");
		else
			sprintf_s(s, l, "((x - %.2f)^2", p.x);
		int k = strlen(s);
		if (p.y == 0)
			sprintf_s(s + k, l - k, " + y^2");
		else
			sprintf_s(s + k, l - k, " + (y - %.2f)^2", p.y);
		k = strlen(s);
		sprintf_s(s + k, l - k, " - %.2f)^3 = %.2f*", 4 * r * r, 108 * r * r * r * r);
		k = strlen(s);
		if (p.x == 0)
			sprintf_s(s + k, l - k, "x^2\n");
		else
			sprintf_s(s + k, l - k, "(x - %.2f)^2\n", p.x);
		return s;
	}

}
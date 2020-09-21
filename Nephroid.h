#pragma once
#ifndef _NEPHROID_H_
#define _NEPHROID_H_
//#include "gtest\gtest_prod.h"
#include <math.h>
namespace lab1b {
	struct Point {
		double x, y; //Координаты точки на плоскости
		Point(double x0 = 0, double y0 = 0) : x(x0), y(y0){}; //Установка значений x и y по умолчанию
	};


	class Nephroid {
	private:
		Point p; //Координаты центра большой окружности
		double r; //Радиус малой окружности
	public:
		Nephroid() : p(), r(1) {};
		Nephroid(double radius);
		Nephroid(const Point& p0, double rad = 1);
		Nephroid(double x0, double y0, double rad = 1);
		//Cеттеры
		Nephroid& setP(Point& p0) { p = p0; return *this; };
		Nephroid& setR(double r0);
		//Геттеры
		Point getP() const{ return p; };
		double getR() const{ return r; };
		//Другие методы
		double length() const { return 24 * r; }; //Длина кривой
		double curveradius(double t = 0) const { return abs(3 * r * sin(t)); }; //Радиус кривизны
		double area() const { return 12 * 3.1415 * r * r; }; //Площадь, ограниченная кривой
		Point coordinates(double t = 0) const; //Координаты x и y в зависимости от параметра
		char* equation() const;	//Вывод уравнения кривой
	};
	
}
#endif
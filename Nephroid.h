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
		Nephroid& setP(Point& p0);
		Nephroid& setR(double r0);
		//Геттеры
		Point getP() const;
		double getR() const;
		//Другие методы
		double length() const; //Длина кривой
		double curveradius(double t = 0) const; //Радиус кривизны
		double area() const; //Площадь, ограниченная кривой
		Point coordinates(double t = 0) const; //Координаты x и y в зависимости от параметра
		std::string equation() const;	//Вывод уравнения кривой
	};
	
}
#endif
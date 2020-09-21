#pragma once
#ifndef _NEPHROID_H_
#define _NEPHROID_H_
//#include "gtest\gtest_prod.h"
#include <math.h>
namespace lab1b {
	struct Point {
		double x, y; //���������� ����� �� ���������
		Point(double x0 = 0, double y0 = 0) : x(x0), y(y0){}; //��������� �������� x � y �� ���������
	};


	class Nephroid {
	private:
		Point p; //���������� ������ ������� ����������
		double r; //������ ����� ����������
	public:
		Nephroid() : p(), r(1) {};
		Nephroid(double radius);
		Nephroid(const Point& p0, double rad = 1);
		Nephroid(double x0, double y0, double rad = 1);
		//C������
		Nephroid& setP(Point& p0) { p = p0; return *this; };
		Nephroid& setR(double r0);
		//�������
		Point getP() const{ return p; };
		double getR() const{ return r; };
		//������ ������
		double length() const { return 24 * r; }; //����� ������
		double curveradius(double t = 0) const { return abs(3 * r * sin(t)); }; //������ ��������
		double area() const { return 12 * 3.1415 * r * r; }; //�������, ������������ ������
		Point coordinates(double t = 0) const; //���������� x � y � ����������� �� ���������
		char* equation() const;	//����� ��������� ������
	};
	
}
#endif
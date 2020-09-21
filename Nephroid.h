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
		Nephroid& setP(Point& p0);
		Nephroid& setR(double r0);
		//�������
		Point getP() const;
		double getR() const;
		//������ ������
		double length() const; //����� ������
		double curveradius(double t = 0) const; //������ ��������
		double area() const; //�������, ������������ ������
		Point coordinates(double t = 0) const; //���������� x � y � ����������� �� ���������
		std::string equation() const;	//����� ��������� ������
	};
	
}
#endif
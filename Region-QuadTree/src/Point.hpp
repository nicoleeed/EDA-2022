#include <bits/stdc++.h>
#pragma once

using namespace std;

class Point {
	public:
		double coords[2];
		typedef double* iterator;
		typedef const double* const_iterator;
		
		Point();
		Point(const Point &p);
		Point(double crd[2]);
		
		void Duplicate(const Point &p);

		double& operator[](size_t index);
		double operator[](size_t index) const;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

	friend std::ostream& operator<<(std::ostream& out, const Point& lhs) {
		out << "( ";
		out << lhs.coords[0] << " - "<< lhs.coords[1] << " )";
		return out;
	}

};

double distance(const Point& one, const Point& two);

bool operator==(const Point& one, const Point& two);

bool operator!=(const Point& one, const Point& two);

Point::Point() {
	this->coords[0]=double(0);
	this->coords[1]=double(0);
}

Point::Point(double crd[2]) {
	this->coords[0]=crd[0];
	this->coords[1]=crd[1];
}

Point::Point(const Point& p){
	this->coords[0]=p.coords[0];
	this->coords[1]=p.coords[1];
}

void Point::Duplicate(const Point& p){
	this->coords[0]=p.coords[0];
	this->coords[1]=p.coords[1];
}

double& Point::operator[](size_t index) {
	return coords[index];
}

double Point::operator[](size_t index) const {
	return coords[index];
}

typename Point::iterator Point::begin() {
	return coords;
}

typename Point::const_iterator Point::begin() const {
	return coords;
}

typename Point::iterator Point::end() {
	return begin() + 2;
}

typename Point::const_iterator Point::end() const {
	return begin() + 2;
}

double distance(const Point& one, const Point& two) {
	double result = 0.0;
	for (size_t i = 0; i < 2; ++i) {
		result += (one[i] - two[i]) * (one[i] - two[i]);
	}
	return sqrt(result);
}

bool operator==(const Point& one, const Point& two) {
	return std::equal(one.begin(), one.end(), two.begin());
}

bool operator!=(const Point& one, const Point& two) {
	return !(one == two);
}


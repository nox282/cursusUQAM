#include <assert.h>
#include <cmath>
#include "point.h"

Point::Point(double _x, double _y) 
  : x(_x), y(_y){
  std::cerr << "Point::Point(" << _x << ", "<< _y <<")" << std::endl;
}

Point::Point(const Point& point)
  : x(point.x), y(point.y){
  std::cerr << "Point::Point(const Point&)"<< point << std::endl;
}

Point::~Point(){
  std::cerr << "Point::~Point()" << this << std::endl;
}

double Point::distance(const Point& point) const {
    double dist = std::pow(point.x - x, 2) + std::pow(point.y - y, 2);
    dist = std::sqrt(dist);
    return dist;
}

std::ostream& operator << (std::ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

std::istream& operator >> (std::istream& is, Point& point) {
  char po, vir, pf;
  is >> po;
  if(is){
    is >> point.x >> vir >> point.y >> pf;
    assert(po=='(');    assert(vir==',');    assert(pf==')');
  }
  return is;
}

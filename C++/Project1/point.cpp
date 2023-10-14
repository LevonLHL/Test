#include"point.h"


void Point::setX(int x) {		//添加一个作用域Point::
	m_X = x;
}
int Point::getX() {
	return m_X;
}
void Point::setY(int y) {
	m_Y = y;
}
int Point::getY() {
	return m_Y;
}
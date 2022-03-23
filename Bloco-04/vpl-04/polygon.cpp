/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
    for (const Point& p: poly.limits) {
        out << " " << p;
    }
    return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  // TODO: implement this method.
    std::vector<Point> lhs_vector = lhs;
    std::vector<Point> rhs_vector = rhs;

    for ( const Point left_point : (const std::vector<Point>) lhs)
    {
        if ( !rhs.contains (left_point) )
        {
            return false;
        }
    }

    for ( const Point right_point : (const std::vector<Point>) rhs)
    {
        if ( !lhs.contains (right_point) )
        {
            return false;
        }
    }
    
    return true;
}

bool Point::contains(const Point& p) const {
    return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

bool RightRectangle::contains(const Point& p) const {
  // TODO: implement this method.
    bool boundX = ( (p.x <= this->limits[1].x) && (p.x >= this->limits[0].x) );

    bool boundY = ( (p.y <= this->limits[1].y) && (p.y >= this->limits[0].y) );

    return (boundX && boundY);
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  // TODO: implement this method.
    this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // TODO: implement this method.
    if (x0 < x1)
    {
        if (y0 < y1)
        {
            this->limits.push_back ( Point (x0, y0) );
            this->limits.push_back ( Point (x1, y1) );
        }
        else 
        {
            this->limits.push_back ( Point (x0, y1) );
            this->limits.push_back ( Point (x1, y0) );
        }
    }
    else
    {
        if (y0 < y1)
        {
            this->limits.push_back ( Point (x1, y0) );
            this->limits.push_back ( Point (x0, y1) );
        }
        else 
        {
            this->limits.push_back ( Point (x1, y1) );
            this->limits.push_back ( Point (x0, y0) );
        }
    }
}
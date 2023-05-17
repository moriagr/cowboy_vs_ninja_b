//
// Created by moria on 5/3/23.
//

#include "Point.hpp"

namespace ariel {

    Point::Point(double myX, double myY) {
        this->x = (double) myX;
        this->y = (double) myY;
    }

    Point::Point() {
        this->x = 0;
        this->y = 0;
    }

    double Point::getX() const {
        return this->x;
    }

    double Point::getY() const {
        return this->y;
    }

    void Point::setX(double myX) {
        this->x = myX;
    }

    void Point::setY(double myY) {
        this->y = myY;
    }

    double Point::distance(Point other) {
        return sqrt(pow(this->x - other.getX(),2) + pow(this->y - other.getY(),2));
    }

    void Point::print() {
        cout << "(" << this->x << " , " << this->y << ")" << endl;
    }

    Point Point::moveTowards(Point origin, Point destination, double distance) {
        if(distance < 0){
            throw std::invalid_argument("distance must be positive");
        }
        double original_distance = origin.distance(destination);
        if (distance >= original_distance) {
            return destination;
        }
        double ratio = distance / original_distance;
        double newX = origin.getX() + (destination.getX() - origin.getX()) * ratio;
        double newY = origin.getY() + (destination.getY() - origin.getY()) * ratio;
        return Point(newX, newY);
    }


};

//
// Created by moria on 5/3/23.
//

#ifndef COWBOY_VS_NINJA_A_POINT_H
#define COWBOY_VS_NINJA_A_POINT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <cmath>

using namespace std;

namespace ariel {

    class Point {
    private:
        double x;
        double y;

    public:
//        Point(float myX, float myY);

        Point(double myX, double myY);

//        Point(int myX, int myY);

        Point();

        double getX() const;

        double getY() const;

        void setX(double myX);

        void setY(double myY);

        double distance(Point other);

        void print();

        static Point moveTowards(Point origin, Point destination, double distance);
    };

}

#endif //COWBOY_VS_NINJA_A_POINT_H

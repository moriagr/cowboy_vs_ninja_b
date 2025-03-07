//
// Created by moria on 5/3/23.
//


#ifndef COWBOY_VS_NINJA_A_CHARACTER_H
#define COWBOY_VS_NINJA_A_CHARACTER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "./Point.hpp"

namespace ariel {

    class Character {
    private:
        string name;
        Point location;
        int hit_num;
        bool in_team;
    public:
        Character(int hit_num_, Point location_, string name_);
        bool isAlive();
        double distance(Character *other);
        void hit(int num);
        string getName() const;
        Point getLocation() const;
        int getHitNum() const;
        bool getInTeam() const;
        void setInTeam(bool inTeam);
        void setName(string name);
        void setLocation(Point location);
        void setHitNum(int hit_num);

        virtual string print() = 0;

        virtual ~Character();

        Character();

        // Define copy constructor
        Character(const Character& other);

        // Define copy assignment operator
        Character& operator=(const Character& other);

        // Define move constructor
        Character(Character&& other) noexcept;

        // Define move assignment operator
        Character& operator=(Character&& other) noexcept;
    };


} // ariel

#endif //COWBOY_VS_NINJA_A_CHARACTER_H

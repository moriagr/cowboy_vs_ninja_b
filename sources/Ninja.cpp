//
// Created by moria on 5/3/23.
//

#include "Ninja.hpp"

namespace ariel {
    Ninja::Ninja(int speed_, int hit_num_, string name_, Point location_) : speed(speed_),
                                                                            Character(hit_num_, location_, name_) {
    }

    Ninja::Ninja() : speed(0),
                     Character(0, Point(0, 0), "") {}

    Ninja::~Ninja() {}

    // Define copy constructor
    Ninja::Ninja(const Ninja &other) :speed(other.getSpeed()),
                                      Character(other.getHitNum(), other.getLocation(), other.getName()) {}

    // Define copy assignment operator
    Ninja &Ninja::operator=(const Ninja &other) {
        this->speed = other.getSpeed();
        this->setHitNum(other.getHitNum());
        this->setLocation(other.getLocation());
        this->setName(other.getName());
        return *this;
    }

    // Define move constructor
    Ninja::Ninja(Ninja&& other) noexcept :speed(other.getSpeed()),
                                            Character(other.getHitNum(), other.getLocation(), other.getName()) {}


// Define move assignment operator
    Ninja &Ninja::operator=(Ninja&& other) noexcept{
        this->speed = other.getSpeed();
        this->setHitNum(other.getHitNum());
        this->setLocation(other.getLocation());
        this->setName(other.getName());
        return  *this;
    }

    void Ninja::move(Character *other) {

    }

    void Ninja::slash(Character *other) {

    }

    int Ninja::getSpeed() const{
        return this->speed;
    }

    string Ninja::print(){
        string str_print = "N " + this->getName() + ": HP: "+to_string(this->getHitNum())+", Location: ("+to_string(this->getLocation().getX())+" , "+to_string(this->getLocation().getY()) + ")";
        return str_print;
    }
} // ariel
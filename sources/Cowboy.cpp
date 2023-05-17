//
// Created by moria on 5/3/23.
//

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(string name, Point location) : Character(110, location, name) {
        this->numOfBalls = 6;
    }

    Cowboy::Cowboy():Character(110, Point(0,0), "") {
        this->numOfBalls = 6;
    }

    // Define copy constructor
    Cowboy::Cowboy(const Cowboy& other):Character(other.getHitNum(), other.getLocation(), other.getName()){
        this->numOfBalls = other.getNumOfBalls();
    }

    // Define copy assignment operator
    Cowboy &Cowboy::operator=(const Cowboy& other){
        this->setHitNum(other.getHitNum());
        this->setLocation(other.getLocation());
        this->setName(other.getName());
        this->numOfBalls = other.getNumOfBalls();

        return *this;
    }

    // Define move constructor
    Cowboy::Cowboy(Cowboy&& other) noexcept:Character(other.getHitNum(), other.getLocation(), other.getName()){
        this->numOfBalls = other.getNumOfBalls();

}

    // Define move assignment operator
    Cowboy &Cowboy::operator=(Cowboy&& other) noexcept{
        this->setHitNum(other.getHitNum());
        this->setLocation(other.getLocation());
        this->setName(other.getName());
        this->numOfBalls = other.getNumOfBalls();

        return *this;
    }

    int Cowboy::getNumOfBalls() const {
        return this->numOfBalls;
    }

    Cowboy::~Cowboy(){} //not finished

    void Cowboy::shoot(Character *other) {
        if( other == this ){
            throw std::runtime_error("You can't shoot yourself");
        }
//        if(!(other->isAlive()) || !(this->isAlive())){
//            throw std::runtime_error("You can't shoot somebody who is already dead");
//        }
        if(this->getNumOfBalls()>0) {
            other->hit(10);
            this->numOfBalls = this->numOfBalls - 1;
        }
    }

    void Cowboy::reload() {
        if(!(this->isAlive())){
            throw std::runtime_error("You can't reload when your dead");

        }

        this->numOfBalls = 6;
    }

    bool Cowboy::hasboolets() {
        return this->numOfBalls > 0;
    }

    string Cowboy::print(){
        string str_print = "C " + this->getName() + ": HP: "+to_string(this->getHitNum())+", Location: ("+to_string(this->getLocation().getX())+" , "+to_string(this->getLocation().getY()) + ")";
        return  str_print;
    }


} // ariel
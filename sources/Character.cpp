//
// Created by moria on 5/3/23.
//

#include "Character.hpp"

namespace ariel {
    Character::Character(int hit_num_, Point location_, string name_) : location(location_), hit_num(hit_num_),
                                                                        name(name_) {

    }

    Character::~Character() {//not finished

    }

    // Define copy constructor
    Character::Character(const Character &other) : Character(other.hit_num, other.location, other.name) {

    }

    // Define copy assignment operator
    Character &Character::operator=(const Character &other){
        this->location = Point(other.getLocation());
        this->hit_num = other.getHitNum();
        this->name = std::move(other.getName());
        return *this;
    }

    // Define move constructor
    Character::Character(Character&& other) noexcept : location(other.location), hit_num(other.hit_num), name(std::move(other.name)) {

    }

    Character::Character(){
        this->location = Point(0,0);
        this->hit_num = 0;
        this->name = "";
    }

    // Define move assignment operator
    Character &Character::operator=(Character &&other) noexcept{
        this->location = Point(other.getLocation());
        this->hit_num = other.getHitNum();
        this->name = std::move(other.getName());
        return *this;
    }

    bool Character::isAlive() {
       return hit_num > 0;
    }

    double Character::distance(Character *other) {
        return this->getLocation().distance(other->getLocation());
    }

    void Character::hit(int num) {

        if(this->hit_num < num){
            this->hit_num = hit_num - num;
        }
        this->hit_num = 0;

    }

    string Character::getName() const {
        return this->name;
    }

    Point Character::getLocation() const {
        return this->location;
    }

    int Character::getHitNum() const{
        return this->hit_num;
    }

    void Character::setName(string name){
        this->name = name;
    }

    void Character::setLocation(Point location){
        this->location = location;
    }

    void Character::setHitNum(int hit_num){
        this->hit_num = hit_num;
    }

}
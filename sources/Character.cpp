//
// Created by moria on 5/3/23.
//

#include "Character.hpp"

namespace ariel {
    Character::Character(int hit_num_, Point location_, string name_) : location(location_), hit_num(hit_num_),
                                                                        name(name_) {
        this->in_team = false;
    }

    bool Character::getInTeam() const{
        return this->in_team;
    }

    void Character::setInTeam(bool inTeam){
        this->in_team = inTeam;
    }

    Character::~Character() {//not finished

    }

    // Define copy constructor
    Character::Character(const Character &other) : Character(other.hit_num, other.location, other.name) {
        this->in_team = other.in_team;

    }

    // Define copy assignment operator
    Character &Character::operator=(const Character &other){
        this->location = Point(other.getLocation());
        this->hit_num = other.getHitNum();
        this->name = std::move(other.getName());
        this->in_team = other.getInTeam();
        return *this;
    }

    // Define move constructor
    Character::Character(Character&& other) noexcept : location(other.getLocation()), hit_num(other.getHitNum()), name(std::move(other.getName())) {
        this->in_team = other.getInTeam();
    }

    Character::Character(){
        this->location = Point(0,0);
        this->hit_num = 0;
        this->name = "";
        this->in_team = false;
    }

    // Define move assignment operator
    Character &Character::operator=(Character &&other) noexcept{
        this->location = Point(other.getLocation());
        this->hit_num = other.getHitNum();
        this->name = std::move(other.getName());
        this->in_team = other.getInTeam();

        return *this;
    }

    bool Character::isAlive() {
        if( this->getHitNum() > 0 ){
            return true;
        }
       return false;
    }

    double Character::distance(Character *other) {
        return this->getLocation().distance(other->getLocation());
    }

    void Character::hit(int num) {
        if(num < 0){
            throw std::invalid_argument("Hit number can't be negative");
        }

//        if(this->hit_num < num){
        this->hit_num = this->hit_num - num;
//        }
//        this->hit_num = 0;

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
//
// Created by moria on 5/3/23.
//

#include "Team.hpp"

namespace ariel {
    Team2::Team2(Character *leader_):Team(leader_) {
    }

    Team2::Team2():Team(){

    }

//    Team2::~Team2(){
//        for (Character* member : this->group) {
//            delete member;
//        }
//    }

    // Define copy constructor
    Team2::Team2(const Team2& other):Team(other){
    }

    // Define copy assignment operator
    Team2 &Team2::operator=(const Team2& other){
        this->setLeader(other.getLeader());
        this->setGroup(other.getGroup());
        return *this;
    }

    // Define move constructor
    Team2::Team2(Team2&& other) noexcept: Team2(other.getLeader()){

    }

    // Define move assignment operator
    Team2 &Team2::operator=(Team2&& other) noexcept{
        this->setLeader(other.getLeader());
        this->setGroup(other.getGroup());
        return *this;
    }

    void Team2::attack(Team *team) {
        if(team == nullptr){
            throw std::invalid_argument("you can't compare between a null team");
        }
        if(!this->getLeader()->isAlive()){
            this->setLeader(this->findClosestLivingCharacter(this->getGroup()));
        }
        Character* enemy = this->findClosestLivingCharacter(team->getGroup());
        for (Character* member : this->getGroup()) {
            if(member->isAlive()) {
                if (std::string(typeid(member).name()).compare("Cowboy") == 6) {
                    Cowboy* temp = dynamic_cast<Cowboy*>(member);
                    temp->shoot(enemy);
                }
                else{
                    Ninja* temp = dynamic_cast<Ninja*>(member);
                    temp->slash(enemy);
                }
                if(!enemy->isAlive()){
                    enemy = this->findClosestLivingCharacter(team->getGroup());
                }
            }
        }
    }

    void Team2::print() const{
        for (Character* member : this->getGroup()) {
            cout << member->print() << endl;
        }
    }
} // ariel
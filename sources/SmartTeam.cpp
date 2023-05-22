//
// Created by moria on 5/3/23.
//

#include "Team.hpp"

namespace ariel {
    SmartTeam::SmartTeam(Character *leader_) : Team(leader_) {
    }

    SmartTeam::SmartTeam() : Team() {
        this->leader = nullptr;
    }

    SmartTeam::~SmartTeam() {
        for (Character* member : this->group) {
            delete member;
        }
    }

    SmartTeam::SmartTeam(const SmartTeam& other):Team(other){
    }

    // Define copy assignment operator
    SmartTeam &SmartTeam::operator=(const SmartTeam& other){
        this->setLeader(other.getLeader());
        this->setGroup(other.getGroup());
        return *this;
    }

    // Define move constructor
    SmartTeam::SmartTeam(SmartTeam&& other) noexcept: SmartTeam(other.getLeader()){

}

    // Define move assignment operator
    SmartTeam &SmartTeam::operator=(SmartTeam&& other) noexcept{
        this->setLeader(other.getLeader());
        this->setGroup(other.getGroup());
        return *this;
    }

    void SmartTeam::attack(Team *team) {

    }

    void SmartTeam::print() const {}

} // ariel
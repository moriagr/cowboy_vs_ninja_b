//
// Created by moria on 5/3/23.
//

#include "Team.hpp"

namespace ariel {
    SmartTeam::SmartTeam(Character *leader_) : Team(
            leader_) {     // I chose to get the ninjas first and then the cowboys because the Ninjas hit harder than cowboys.
    }

    SmartTeam::SmartTeam() : Team() {
    }

    void SmartTeam::getNewOrganized() {
        vector<Character *> group_cowboy;
        vector<Character *> group_ninja;
        for (Character* member : this->getGroup()) {
            Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
            if (cowboy) {
                group_cowboy.push_back(member);
            }
            else{
                group_ninja.push_back(member);
            }
        }

        group_ninja.insert(group_ninja.end(), group_cowboy.begin(), group_cowboy.end());
        this->setGroupOrganized(group_ninja);
    }

    void SmartTeam::attack(Team *team) {
        if (team == nullptr) {
            throw std::invalid_argument("you can't compare between a null team");
        }
        if (team->stillAlive() <= 0) {
            throw std::runtime_error("You can't attack a dead team");
        }

        if (this->stillAlive() <= 0) {
            throw std::runtime_error("The can't attack a team when all the original team is dead");
        }

        this->getNewOrganized();
        if(!this->getLeader()->isAlive()){
            this->setLeader(this->findClosestLivingCharacter(this->getGroupOrganized()));
        }


        Character* enemy = this->findClosestLivingCharacter(team->getGroupOrganized());

        for (Character* member : this->getGroupOrganized()) {
            if(member->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(member);
                Ninja* ninja = dynamic_cast<Ninja*>(member);
                if(cowboy){
                    if(cowboy->hasboolets()){
                        cowboy->shoot(enemy);
                    }
                    else{
                        cowboy->reload();
                    }
                }
                else if(ninja){
                    if(ninja->distance(enemy) < 1) {
                        ninja->slash(enemy);
                    }
                    else{
                        ninja->move(enemy);
                    }
                }
                if(!enemy->isAlive()){
                    enemy = this->findClosestLivingCharacter(team->getGroupOrganized());
                    if(enemy == nullptr){
                        return;
                    }
                }
            }
        }
    }

    void SmartTeam::print() const {
        for (Character *member: this->getGroup()) {
            Ninja *ninja = dynamic_cast<Ninja *>(member);
            if (ninja) {
                cout << member->print() << endl;
            }
        }

        for (Character *member: this->getGroup()) {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(member);
            if (cowboy) {
                cout << member->print() << endl;
            }
        }
    }

} // ariel
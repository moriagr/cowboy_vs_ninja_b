//
// Created by moria on 5/3/23.
//

#include "Team.hpp"

namespace ariel {

    Team::Team(Character *leader_){
        this->add(leader_);
//        this->getOrganized();

        this->leader = leader_;
//        this->group = NULL;
    }

    Team::Team(){
        this->leader = nullptr;
//        this->group = NULL;

    }
    Team::~Team(){
        for (Character* member : this->group) {
            delete member;
        }
    }

    // Define copy constructor
    Team::Team(const Team& other) {
        this->leader = other.getLeader();
        this->group = other.getGroup();
    }

    // Define copy assignment operator
    Team &Team::operator=(const Team &other) {
        this->group = other.getGroup();
        this->leader = other.getLeader();
        return *this;
    }

    // Define move constructor
    Team::Team(Team &&other) noexcept {
        this-> leader = other.getLeader();
        this-> group = other.getGroup();
    }

    // Define move assignment operator
    Team &Team::operator=(Team &&other) noexcept{
        this-> leader = other.getLeader();
        this-> group = other.getGroup();
        return *this;
    }


    void Team::add(Character *other) {
        if(other->getInTeam()){
            throw std::runtime_error("character already in team");
        }
        if (this->group.size() >= 10) {
            throw std::runtime_error("In team there must be at most 10 teammates");
        }
        this->group.push_back(other);
        other->setInTeam(true);

        this->getOrganized();
    }

    Character* Team::getLeader() const{
        return this->leader;
    }

    void Team::setLeader(Character* leader_){
        this->leader = leader_;
    }

    void Team::setGroup(vector<Character *> group_){
        this->group = group_;
    }

    vector<Character *> Team::getGroupOrganized() const{
        return this->group_organized;
    }

    void Team::attack(Team *team){
        if(team == nullptr){
            throw std::invalid_argument("You can't compare between a null team");
        }

        if(team->stillAlive() <= 0){
            throw std::runtime_error("You can't attack a dead team");
        }

        if(this->stillAlive() <= 0){
            throw std::runtime_error("The can't attack a team when all the original team is dead");
        }

        if(!this->getLeader()->isAlive()){
           this->leader = findClosestLivingCharacter(this->getGroupOrganized());
        }

        Character* enemy = findClosestLivingCharacter(team->getGroupOrganized());

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
                    if(ninja->distance(enemy) < 1){
                        ninja->slash(enemy);
                    }
                    else{
                        ninja->move(enemy);
                    }
                }

                if(!enemy->isAlive()){
                    enemy = findClosestLivingCharacter(team->getGroupOrganized());
                    if(enemy == nullptr){
                        return;
                    }
                }
            }
        }

    }

    Character* Team::findClosestLivingCharacter(vector<Character *> group) const {
        double minDistance = std::numeric_limits<double>::max();
        Character* closestCharacter = nullptr;

        for (Character* member : group) {
            if (member->isAlive()) {
                double distance = member->distance(this->getLeader());
                if (distance < minDistance) {
                    minDistance = distance;
                    closestCharacter = member;
                }
            }
        }

        return closestCharacter;
    }

    int Team::stillAlive() const {
        int count = 0;
        for (Character* member : this->group) {
            if (member->isAlive()) {
                count++;
            }
        }
        return count;
    }


    vector<Character *> Team::getGroup() const{
        return group;
    }

    void Team::getOrganized() {
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

        group_cowboy.insert(group_cowboy.end(), group_ninja.begin(), group_ninja.end());
        this->group_organized = group_cowboy;
    }

    void Team::setGroupOrganized(vector<Character *> groupOrganized){
        this->group_organized = groupOrganized;
    }

    void Team::print() const{
         for (Character* member : this->group_organized) {
            cout << member->print() << endl;
        }
    }
}

//
// Created by moria on 5/3/23.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_H
#define COWBOY_VS_NINJA_A_TEAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "./OldNinja.hpp"
#include "./YoungNinja.hpp"
#include "./TrainedNinja.hpp"
#include "./Cowboy.hpp"
#include <typeinfo>

#include <vector>

namespace ariel {

    class Team {
    private:
        Character *leader;
        vector<Character *> group;
        vector<Character *> group_organized;

        void getOrganized();

        vector<Character *> getGroupOrganized() const;

    protected:
        Character *findClosestLivingCharacter(vector<Character *> group) const;

    public:
        Team(Character *leader_);

        Team();

        ~Team();

        // Define copy constructor
        Team(const Team &other);

        // Define copy assignment operator
        Team &operator=(const Team &other);

        // Define move constructor
        Team(Team &&other)

        noexcept;

        // Define move assignment operator
        Team &operator=(Team &&other)

        noexcept;

        void setLeader(Character *leader_);

        void add(Character *other);

        void attack(Team *team);

        int stillAlive() const;

        void setGroup(vector<Character *> group_);

        void print() const;

        Character *getLeader() const;

        vector<Character *> getGroup() const;
    };

    class SmartTeam : public Team {
    public:
        SmartTeam(Character *leader_);

        SmartTeam();

        void attack(Team *team);

        void print() const;
    };

    class Team2 : public Team {
    public:
        Team2(Character *leader_);

        Team2();

        void attack(Team *team);

        void print() const;
    };
}

#endif //COWBOY_VS_NINJA_A_TEAM_H

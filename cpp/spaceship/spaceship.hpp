#ifndef __H__SPACESHIP__
#define __H__SPACESHIP__

#include <string>
class Spaceship
    public:
        Spaceship();
        Spaceship(std::string name, int hp, float shield)
        std::string getStudent();
        // :: = namespace (where the function lives)
        
    private:
        std::string name;
        int hp;
        float shield;
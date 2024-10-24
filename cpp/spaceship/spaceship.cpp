#include "spaceship.hpp"

Spaceship::Spaceship() {
    name = "Unnamed";
    hp = 100
    shield = 1.0f
}

Spaceship::Spaceship(std::string name, int hp, float shield) {
    this->name = name;
    this->hp = hp;
}

void Spaceship::printShip() {
    std::cout << this->name << ": " << this->hp << ": " << this->shield << std:endl;
}

int Spaceship::getHp() {
    return this->hp;
}

void Spaceship::setHp(int hp) {
    this->hp = hp;
}

void changeHp(Spaceship& ship, int hp) {
    ship.setHp(hp);
}

int main(int argc, char** argv) {
    Spaceship firefly;
    Spaceship enterprise("Enterprise", 100, 1.0f);
    firefly.printShip();
    enterprise.printShip();
}
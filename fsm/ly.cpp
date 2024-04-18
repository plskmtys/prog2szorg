/**
 *  \file ly.cpp
 *
 *  Ly számláló és állapotainak megvalósítása
 *  fsm + singleton tervezési minta felhasználásával
 *
 */

#include <iostream>
#include "ly.h"

/// Ly számláló osztály
class Ly : public Entity<char>{
    int sz;
public:
    Ly() : Entity<char>(Alap::getInstance()), sz(0) {}
    int get() const { return sz; }
    void add(int i) { sz += i; }
};

/// Alap állapot inputja
void Alap::Input(Entity<char>* ly, char ch) {
    if (ch == 'l' || ch == 'L') {
        ly->setState(Ljott::getInstance());
    }
}

/// Ljott állapot inputja
void Ljott::Input(Entity<char>* ly, char ch) {
    if (ch == 'l' || ch == 'L') {
        ly->setState(LLjott::getInstance());
    } else {
        if (ch == 'y' || ch == 'Y') dynamic_cast<Ly*>(ly)->add(1);
        ly->setState(Alap::getInstance());
    }
}

/// LLjott állapot inputja
void LLjott::Input(Entity<char>* ly, char ch) {
    if (ch == 'y' || ch == 'Y')
        dynamic_cast<Ly*>(ly)->add(2);
    if (ch != 'l' && ch != 'L')
        ly->setState(Alap::getInstance());
}

int main() {
    Ly ly;
    char ch;

    std::cout << "Johet a duma:\n";
    while (std::cin >> std::noskipws >> ch)
        ly.Input(ch);
    std::cout << "ly-ok szama:" << ly.get() << std::endl;

    return 0;
}



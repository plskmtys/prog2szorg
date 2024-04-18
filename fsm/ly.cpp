/**
 *  \file ly.cpp
 *
 *  Ly sz�ml�l� �s �llapotainak megval�s�t�sa
 *  fsm + singleton tervez�si minta felhaszn�l�s�val
 *
 */

#include <iostream>
#include "ly.h"

/// Ly sz�ml�l� oszt�ly
class Ly : public Entity<char>{
    int sz;
public:
    Ly() : Entity<char>(Alap::getInstance()), sz(0) {}
    int get() const { return sz; }
    void add(int i) { sz += i; }
};

/// Alap �llapot inputja
void Alap::Input(Entity<char>* ly, char ch) {
    if (ch == 'l' || ch == 'L') {
        ly->setState(Ljott::getInstance());
    }
}

/// Ljott �llapot inputja
void Ljott::Input(Entity<char>* ly, char ch) {
    if (ch == 'l' || ch == 'L') {
        ly->setState(LLjott::getInstance());
    } else {
        if (ch == 'y' || ch == 'Y') dynamic_cast<Ly*>(ly)->add(1);
        ly->setState(Alap::getInstance());
    }
}

/// LLjott �llapot inputja
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



/**
 *  \file ly.cpp
 *
 *  Ly számláló állapota és entitása.
 *  fsm + singleton tervezési minta felhasználásával
 *
 */

#include "fsm.hpp"

/// LyState
/// Ly számláló állapotosztályának alapja
class LyState : public EntityState<char> {
public:
    void Input(Entity<char>*, char) {}
    void Enter(Entity<char>*) {}
    void Leave(Entity<char>*) {}
};

/// Alap állapot
class Alap : public LyState {
    Alap() {}
    Alap(const Alap&);
    Alap& operator=(const Alap&);
public:
    static Alap* getInstance() {
        static Alap singleton;
        return &singleton;
    }
    void Input(Entity<char>* ly, char ch);
};

/// Ljott állapot
class Ljott : public LyState {
    Ljott() {}
    Ljott(const Ljott&);
    Ljott& operator=(const Ljott&);
public:
    static Ljott* getInstance() {
        static Ljott singleton;
        return &singleton;
    }
    void Input(Entity<char>* ly, char ch);
};

/// LLjott állapot
class LLjott : public LyState {
    LLjott() {}
    LLjott(const LLjott&);
    LLjott& operator=(const LLjott&);
public:
    static LLjott* getInstance() {
        static LLjott singleton;
        return &singleton;
    }
    void Input(Entity<char>* ly, char ch);
};

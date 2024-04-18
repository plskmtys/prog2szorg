/**
 *  \file fsm.hpp
 *
 *  Generikus inputot kap� finite state machine (FSM)
 *  fsm tervez�si minta felhaszn�l�s�val
 *
 */

/// El�deklar�ci�
template <typename T>
class Entity;

/// �llapotok absztrakt alposzt�lya
template <typename T>
class EntityState {
public:
    virtual void Input(Entity<T>*, T) = 0;
    virtual void Enter(Entity<T>*) = 0;
    virtual void Leave(Entity<T>*) = 0;
    virtual ~EntityState() {}
};

/// Entit�s alaposzt�lya
template <typename T>
class Entity {
    EntityState<T>* currentState;
public:
    Entity(EntityState<T>* st) : currentState(st) {}
    void setState(EntityState<T>* st) {
        currentState->Leave(this);
        currentState = st;
        currentState->Enter(this);
    }
    void Input(T data) {
        currentState->Input(this, data);
    }
    virtual ~Entity() {}
};

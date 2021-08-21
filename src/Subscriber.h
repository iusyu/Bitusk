/*
 *
 *
 */
#include <list>
#include <algorithm>

#pragma once

class Observer;
class Subject;

class Observer{
public:
    virtual void response(Subject* );
};

class Subject{
public:
    virtual void registerObserver(Observer* observer);
    virtual void removeObserver(Observer* observer);
    virtual void notifyObserver();

private:
    std::list<Observer*> observers;

};

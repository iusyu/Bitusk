/*
 *
 *
 */
#include <list>
#pragma once


class Observer{
public:
    virtual void response();
};

class Subject{
public:
    virtual void registerObserver(Observer* observer);
    virtual void removeObserver(Observer* observer);
    virtual void notifyObserver();

private:
    std::list<Observer*> observers;

};
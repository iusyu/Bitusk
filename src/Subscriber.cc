#include "Subscriber.h"


void Observer::response(Subject* obj)
{
    // do something
}

void Subject::registerObserver(Observer *observer)
{
    observers.push_back(observer)
}


void Subject::removeObserver(Observer *observer)
{
    observers.remove(observer);
}


void Subject::notifyObserver()
{
    std::for_each(observers.begin(), observers.end(), [](auto p){
        p->response();
    });
}

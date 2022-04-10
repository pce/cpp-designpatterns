#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <string>
#include <vector>

template <typename>
struct Observer;

template <typename T>
struct Observable
{
    std::vector<Observer<T> *> observers;

public:
    void notify(T &source, const std::string &action_name)
    {
        for (auto observer : observers)
            observer->update(source, action_name);
    }

    void subscribe(Observer<T> &observer)
    {
        observers.push_back(&observer);
    }

    void unsubscribe(Observer<T> &observer)
    {
        observers.erase(
            remove(observers.begin(), observers.end(), &observer),
            observers.end());
    }
};

#endif // OBSERVABLE_H_

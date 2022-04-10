#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>

template <typename T>
struct Observer
{
  virtual void update(
      T &source,
      const std::string &action_name) = 0;
};

#endif

#include <iostream>
#include <vector>

#include "observer.hpp"
#include "observable.hpp"

using namespace std;

// This example is just a Proof of Concept as part of an exercise:
// Rat's attack in Swarms, therefore one rat has the power of all rats in this Game


struct Game
{
  // power of rats
  int attack{0};
};

struct Rat : Observable<Rat>
{
  Game &game;
  int attack{1};

  Rat(Game &game) : game(game)
  {
  }

  void init()
  {
    // constructor not subscribed
    notify(*this, "spawn");
  }

  void doAttack()
  {
    cout << "Attack with the power of the swarm: " << this->game.attack << endl;
  }

  ~Rat()
  {
    // rat dies
    notify(*this, "destroy");
  }
};

struct RatConcreteObserver
    : public Observer<Rat>
{
private:
  void update(Rat &rat, const std::string &action_name) override
  {
    cout << "Rat's " << action_name << ", sum has changed to ";
    if (action_name == "spawn")
    {
      cout << "Rat's " << action_name << ", sum has changed to ";
      rat.game.attack += rat.attack;
    }
    if (action_name == "destroy")
    {
      rat.game.attack -= rat.attack;
    }
    cout << rat.attack << endl;
  }
};

auto main() -> int
{
  Game game;
  RatConcreteObserver ro;

  Rat rat(game);
  rat.subscribe(ro);
  rat.init();

  rat.doAttack();

  Rat rat2(game);
  rat2.subscribe(ro);
  rat2.init();

  rat.doAttack();
  rat2.doAttack();

  return 0;
}

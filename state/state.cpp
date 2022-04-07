
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


struct State {

};


struct OnlineState : State
{
    OnlineState() 
    {
        cout << "network is online\n";
    }
};

struct OfflineState : State
{
    OfflineState() 
    {
        cout << "network is offline\n";
    }
};

class NetworkSwitch 
{
    State *state;
    public:
    NetworkSwitch()
    {
        state = new OfflineState;
    }
    void SetState(State* state) 
    {
        this->state = state;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


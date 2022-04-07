
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class NetworkSwitch;

struct State 
{
    virtual void OnLine(NetworkSwitch* networkSwitch) 
    {
        cout << "network is already online" << endl;
    }
    virtual void OffLine(NetworkSwitch* networkSwitch) 
    {
        cout << "network is already offline" << endl;
    }
};


struct OnlineState : State
{
    OnlineState() 
    {
        cout << "network is online" << endl;
    }

    void OffLine(NetworkSwitch* networkSwitch) override;
};

struct OfflineState : State
{
    OfflineState() 
    {
        cout << "network is offline" << endl;
    }

    void OnLine(NetworkSwitch* networkSwitch) override;

};


class NetworkSwitch 
{
    State *state;
    public:
    NetworkSwitch()
    {
        state = new OfflineState();
    }
    void SetState(State* state) 
    {
        this->state = state;
    }

    void OnLine() 
    {
        state->OnLine(this);
    }

    void OffLine() 
    {
        state->OffLine(this);
    }
};

void OnlineState::OffLine(NetworkSwitch* networkSwitch) 
{
     networkSwitch->SetState(new OfflineState());
     delete this;
};

void OfflineState::OnLine(NetworkSwitch* networkSwitch) 
{
     networkSwitch->SetState(new OnlineState());
     delete this;
};


int main(int argc, char const *argv[])
{
    NetworkSwitch ns;
    ns.OnLine();
    ns.OffLine();
    ns.OffLine();
    return 0;
}


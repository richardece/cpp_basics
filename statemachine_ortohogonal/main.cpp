// Example based on Boost statechart
// https://github.com/CodesBay/State-Machine-Using-Boost-Statechart
// Shows how to create state machine, add manual and custom event handler, and multiple event handlers
// Pending: How to create substates or meta state 

//Just extract the Boost header files under /usr/local/

#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include<iostream>
using namespace std;
namespace sc = boost::statechart;
namespace mpl = boost::mpl;

/* This is an example of a state that has parallel internal states ( means that are independent of each other)
 * There are 3 orthogonal regions called <0>, <1> and <2>
 * Substate(s) must belong to one orthogonal region
 * Transition is allowed ONLY if substates belong to the same orthogonal region.
 *
 * */
// The main state
struct firstState;

// Forward Declarator : Multiple Inner States
struct firstState_Inner_1_0;
struct firstState_Inner_2;
struct firstState_Inner_3;
struct firstState_Inner_1_1;
struct firstState_Inner_1_2;

struct event1 : sc::event<event1> {};
struct event2 : sc::event<event2> {};

// Creating state machine with firstState
struct statemachine : sc::state_machine<statemachine, firstState> {};

// Declare the initial state per orthogonal region
struct firstState : sc::simple_state<firstState, statemachine,
        mpl::list<firstState_Inner_1_0, firstState_Inner_2, firstState_Inner_3 > > {};

// Create constructors of orthogonal region <0> inner states
struct firstState_Inner_1_0 : sc::simple_state<firstState_Inner_1_0, firstState::orthogonal<0> > {
    firstState_Inner_1_0()    { cout << "In State => firstState_Inner_1_0 entry" << endl; }
    void exit()             { cout << "In State => firstState_Inner_1_0 exit" << endl; }
    typedef sc::transition<event1, firstState_Inner_1_1> reactions;
};
struct firstState_Inner_1_1 : sc::simple_state<firstState_Inner_1_1, firstState::orthogonal<0> > {
    firstState_Inner_1_1()   { cout << "In State => firstState_Inner_1_1 entry" << endl; }
    void exit()                 { cout << "In State => firstState_Inner_1_1 exit" << endl; }
    typedef sc::transition<event2, firstState_Inner_1_2> reactions;

};
struct firstState_Inner_1_2 : sc::simple_state<firstState_Inner_1_2, firstState::orthogonal<0> > {
    firstState_Inner_1_2()   { cout << "In State => firstState_Inner_1_2 entry" << endl; }
    void exit()                 { cout << "In State => firstState_Inner_1_2 exit" << endl; }
};

// Create constructors of orthogonal region <1> inner states
struct firstState_Inner_2 : sc::simple_state<firstState_Inner_2, firstState::orthogonal<1> > {
    firstState_Inner_2()    { cout << "In State => firstState_Inner_2 entry" << endl; }
    void exit()             { cout << "In State => firstState_Inner_2 exit" << endl; }
};

// Create constructors of orthogonal region <2> inner states
struct firstState_Inner_3 : sc::simple_state<firstState_Inner_3, firstState::orthogonal<2> > {
    firstState_Inner_3()    { cout << "In State => firstState_Inner_3 entry" << endl; }
    void exit()             { cout << "In State => firstState_Inner_3 exit" << endl; }
};

// Trigger change in state from firstState_Inner_1_0
int main() {
    statemachine sm;
    // This will start with 3 Initial state
    cout << "==Will initiate sm" << endl;
    sm.initiate();
    cout << "==finished sm initialization" << endl;

    cout << "==Will process event1" << endl;
    sm.process_event(event1());
    cout << "==Will process event2" << endl;
    sm.process_event(event2());
    return 0;
}
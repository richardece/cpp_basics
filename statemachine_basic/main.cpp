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

//Forward declaration of states
struct firstState;
struct secondState;
struct thirdState;
struct fourthState;

//Declare a state machine called "statemachine", with starting state called "firstState"
struct statemachine : sc::state_machine<statemachine, firstState> {
    //Constructor
    statemachine() { cout << "Starting => statemachine" << endl; }
    ~statemachine() { cout << "Exiting => statemachine" << endl; }
};

//Declare events
struct event_MoveToFirstState   : sc::event<event_MoveToFirstState>     {};
struct event_MoveToSecondState  : sc::event<event_MoveToSecondState>    {};
struct event_MoveToThirdState   : sc::event<event_MoveToThirdState>     {};
struct event_MoveToFourthState  : sc::event<event_MoveToFourthState>    {};

struct fourthStateInner1;
struct fourthStateInner2;
struct fourthStateInner3;
struct event_MoveToFourthInner1 : sc::event<event_MoveToFourthInner1>   {};
struct event_MoveToFourthInner2 : sc::event<event_MoveToFourthInner2>   {};
struct event_MoveToFourthInner3 : sc::event<event_MoveToFourthInner3>   {};

//State must belong to a state machine
struct firstState : sc::simple_state<firstState, statemachine>
{
    firstState() { cout << "In State => firstState => Entry " << endl; }
    ~firstState() { cout << "In State => firstState => Exit " << endl; }
    //Exit function is called when the state machine moves to another state.
    //This gets called before the deconstructor
    void exit() { cout << "exit() called in State => firstState" << endl; }
	/* There are 2 types of event handlers:
	 * 1. Automated - state machine takes care of moving to another state
	 * 2. Manual - need to handle everything, including transition to the next state
	 * Automated event handlers are shown here. If there are multiple transitions, it has to be grouped
	 * under boost::mpl::list
	 * Notice that the automated event handlers only change state. If we want to perform some actions, it
	 * will be added inside the constructor of the next state.
	 * */
	#if 0
	//Single automated event handler
	//First argument is the event, second argument is the next state
	typedef sc::transition<event_MoveToSecondState, secondState> reactions;
	#else
	//Multiple automated event handler in list
	typedef mpl::list< 
		sc::transition<event_MoveToSecondState, secondState>,
		sc::transition<event_MoveToThirdState, thirdState> 
	> reactions;
	#endif
};

//This state also belongs to "statemachine"
struct secondState : sc::simple_state<secondState, statemachine>
{
	secondState() { cout << "In State => secondState => Entry" << endl; }
    ~secondState() { cout << "In State => secondState => Exit" << endl; }

	/* This is an example of manual event handlers.
	 * Inside the manual event handler, we can perform some actions.
	 * We can also choose to go to different states depending on the result of the actions.
	 * There is also an option to remain inside the current state by "return discard_event()"
	 * instead of "return transit<someOtherState>()".
	 * Similar to automated event handlers, we also use boost::mpl::list to create multiple manual event handlers.
	 * */
	#if 0
	//Single custom event handler
	typedef sc::custom_reaction<event_MoveToFirstState> reactions;
	sc::result react(const event_MoveToFirstState &event) {
		cout << "Custom event handler. event:event_MoveToFirstState" << endl;
		return transit<firstState>();
	}
	#else
	//Multiple manual event handler
	typedef mpl::list <
		sc::custom_reaction<event_MoveToFirstState>,
		sc::custom_reaction<event_MoveToThirdState>
	> reactions;

	sc::result react(const event_MoveToFirstState &event) {
		cout << "Custom event handler. event:event_MoveToFirstState" << endl;
		return transit<firstState>();
	}
	sc::result react(const event_MoveToThirdState &event) {
		cout << "Custom event handler. event:event_MoveToThirdState" << endl;
		return transit<thirdState>();
	}
	#endif
};

//This state also belongs to "statemachine"
struct thirdState : sc::simple_state<thirdState, statemachine>
{
    thirdState() { cout << "In State => thirdState => Entry" << endl; }
    ~thirdState() { cout << "In State => thirdState => Exit" << endl; }

    //Multiple event handler
	//Combined automated  and manual event handler
	typedef mpl::list <
    	//In the automated event handler, this will just move to the next state.
    	//The action will be performed in the next state
		sc::transition<event_MoveToFirstState, firstState>,
		sc::transition<event_MoveToFourthState, fourthState>,
		//But if we want to perform some action before transition, we can use manual event handler.
		sc::custom_reaction<event_MoveToSecondState>
	> reactions;

	sc::result react(const event_MoveToSecondState &event) {
		cout << "Custom event handler. event:event_MoveToSecondState" << endl;
		return transit<secondState>();
	}
};

//Example of state within a state or meta-states
//Each meta state can move to other meta state
//It is also possible to go transition to higher level states
struct fourthState : sc::simple_state<fourthState, statemachine, fourthStateInner1>{
    fourthState() {cout << "In State => fourthState => Entry" << endl; }
    ~fourthState() {cout << "In State => fourthState => Exit" << endl; }

};
struct fourthStateInner1 : sc::simple_state<fourthStateInner1, fourthState>{
    fourthStateInner1() {cout << "In State => fourthState => Inner1 => Entry" << endl; }
    ~fourthStateInner1() {cout << "In State => fourthState => Inner1 => Exit" << endl; }
    typedef sc::transition<event_MoveToFourthInner2, fourthStateInner2> reactions;
};
struct fourthStateInner2 : sc::simple_state<fourthStateInner2, fourthState>{
    fourthStateInner2() {cout << "In State => fourthState => Inner2 => Entry" << endl; }
    ~fourthStateInner2() {cout << "In State => fourthState => Inner2 => Exit" << endl; }
    typedef sc::transition<event_MoveToFourthInner3, fourthStateInner3> reactions;
};
struct fourthStateInner3 : sc::simple_state<fourthStateInner3, fourthState>{
    fourthStateInner3() {cout << "In State => fourthState => Inner3 => Entry" << endl; }
    ~fourthStateInner3() {cout << "In State => fourthState => Inner3 => Exit" << endl; }
    typedef sc::transition<event_MoveToFirstState, firstState> reactions;
};

int main() {
	statemachine sm;
	sm.initiate();
	//After the initialization, we will observe that the state machine will enter its first state
	cout << "state machine has been initialized" << endl;
#if 1
    cout << "=== Will move to second state" << endl;
	sm.process_event(event_MoveToSecondState());
    cout << "=== Will move to third state" << endl;
	sm.process_event(event_MoveToThirdState());
    cout << "=== Will move to fourth state" << endl;
	sm.process_event(event_MoveToFourthState());
#endif
	cout << "=== Will move to fourth state, inner 2" << endl;
    sm.process_event(event_MoveToFourthInner2());
    cout << "=== Will move to fourth state, inner 3" << endl;
    sm.process_event(event_MoveToFourthInner3());
    cout << "=== Will move to first state" << endl;
    sm.process_event(event_MoveToFirstState());

    //cout << "=== Will move to third state" << endl;
    //sm.process_event(event_MoveToThirdState());
    cout << "=== Bye"<<endl;
}
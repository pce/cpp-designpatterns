# Cpp-DesignPatterns

## Behavioural

### Intepreter

Processing of structured, textual input and conversion into OOP structures by lexing (decomposition into tokens) and subsequent parsing (interpretation of tokens).

#### Examples

- [x] Calculator


### State

The state patterns allow an object to behave differently.
It defines the state as an interface that all states implement.

Instead of `STATE_ONLINE` and `STATE_OFFLINE`, each State can encapsulated in a class that implements the state interface. 
Each State can be mapped into a class, i.e. `OnLineState` and `OffLineState`.

Each state needs a reference to the context class, e.g. `NetworkSwitch`. 
For example, a constructor injection and Context as a member that allows to switch to a new state.

Here is a clear difference to the Strategy Pattern: The client cannot know the internal states, while with Strategy the client selects the strategy.  
Strategy is like flexible subclassing. 

The State pattern allows you to replace a set of decision trees by encapsulating the behavior. 
We've all seen and wrote many conditionals in the form of unacceptably complex, nested if and else rules.

Representing State by a class and not just by an value of a enum, each class owns the code and can manage transitions to another state. 

Another interesting architecture could be "Hierarchical State Machines" or a stack of states where events and state updates are delivered from the top "SuperState" to the bottom "SubState" and subsequent rendering from the bottom up. 
This could also reduce code duplication and higher cohesion of state classes.




#### Examples

- [x] Classic State Pattern 
- [ ] modern State Pattern 
- [ ] Object-Oriented Decision Architecture in AI (hopefully in one of my next blog entries)

#### Classic State Pattern

The NetworkSwitch is the Context Class that can have the internal States.


### Observer

The Observer pattern defines a onbe-to-many dependency bewtween objects.
Loose coupling of Subject and Observer allows to build a felxible OO System that scales.
  
There are many differnet ways to implement the observer pattern.
The Terminology varies: observer and observable, event and subscriber, signal and slot (QT, boost)
, broadcaster and listener.

#### Examples

- [x] Classic Observer Pattern 
- [ ] modern Observer Pattern 



# References

- GoF "Design Patterns: Elements of Reusable Object-Oriented Software"
- Head First Design Patterns
- Nesteruk, Dmitri  "design patterns in modern c++"

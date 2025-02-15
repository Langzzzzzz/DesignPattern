### Example Output
Original Object:
Object Address: 0x16d71eff8
Basic Value: 10
Pointer Data: 20
Smart Pointer Data: 30
Vector Data: 1 2 3 4 5 
Text: Hello World

Cloned Object:
Object Address: 0x1487040c0
Basic Value: 11
Pointer Data: 20
Smart Pointer Data: 30
Vector Data: 1 2 3 4 5 
Text: Hello World

### Key Points
- Create the prototype interface and declare the clone method in it.
- The Prototype base class should declare Clone() as a pure virtual function. This ensures that all derived classes implement their own copy logic.
- Each concrete prototype class should implement Clone() using its copy constructor.
- Avoid shallow copy
  - If your class contains raw pointers, make sure to allocate new memory in Clone().
---
Reference: https://refactoring.guru/design-patterns/prototype
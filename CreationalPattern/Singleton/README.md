### When use Singletom Pattern
A class in your program should have just a single instance available to all clients; for example, a single database object shared by different parts of the program.

### How to implement
- static field for storing singleton instance
- static public getInstance() for getting instance.
- Implement "Lazy initialization" inside the static function. 
  - Lazy initialization means that It should create a new object on its first call and put it into the static field.
- Make the constructor of the class private. The static method of the class will still be able to call the constructor, but not the other objects
- "delete" copy constructor and assignment operator to avoid copying.

### Relationship with other patterns
- A `Facade` class can often be transformed into a `Singleton` since a single facade object is sufficient in most cases.
- `Abstract Factories`, `Builders` and `Prototypes` can all be implemented as `Singletons`.
- If you somehow managed to reduce all shared states of the objects to just one flyweight object. `Flyweight` would resemble `Singleton`.

### reference:
https://refactoring.guru/design-patterns/singleton
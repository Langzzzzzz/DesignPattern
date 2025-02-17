### How to Implement
- If an object has many optional parameters. we can use Builder pattern
- Method chaining: Return *this to allow setBrand().setHorsePower().build();
- Use friend class to allow private field modifications
- Use Director for standardized object creation.
- Create a concrete builder class for each of the product representations and implement their construction steps. (SportsCarBuilder and FamilyCarBuilder)
---
Reference: https://refactoring.guru/design-patterns/builder
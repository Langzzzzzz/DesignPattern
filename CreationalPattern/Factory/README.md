### How to implement
- Make all products follow the same interface. This interface should declare methods that make sense in every product.
- Use std::unique_ptr instead of raw pointers to avoid memory leaks.
- If the base class does not have a virtual destructor, deleting a derived object via a base pointer will cause memory leaks.
- Clients should never use new directly.
- Handle Invalid Input in the Factory

| Feature               | Simple Factory 🏭            | Factory Method 🏗️           | Abstract Factory 🏢           |
|----------------------|-------------------------|------------------------|------------------------|
| **Definition**       | A single factory class creates different products based on input. | A base factory class defines a factory method, and subclasses decide which product to create. | A factory that produces **multiple related objects** (a family of products). |
| **Number of Factories** | One factory class. | Multiple concrete factories (subclasses). | Multiple factories for different product families. |
| **Number of Products** | Can create **multiple** unrelated products. | Creates **only one type of product**, but allows subclasses to change its type. | Creates **a group of related products** (e.g., Windows UI vs. Mac UI). |
| **Extensibility** | ❌ **Modifying the factory requires editing its code** (violates Open/Closed Principle). | ✅ **New product types can be added by creating new factory subclasses**. | ✅ **Ensures consistency when creating multiple objects that work together**. |
| **Polymorphism** | ❌ Does not support polymorphism well. | ✅ Uses inheritance and polymorphism. | ✅ Uses inheritance and polymorphism. |
| **Flexibility** | ❌ Hard to extend; all logic is inside one factory. | ✅ Flexible; different subclasses create different products. | ✅ Best for large-scale systems where different product families exist. |
| **Best Use Case** | When there are **few product variations**, and object creation logic is simple. | When a system should delegate **which product to create** to subclasses. | When multiple related objects need to be created **consistently**. |
| **Example** | A `VehicleFactory` that returns `Car` or `Bike` based on a string input. | A `DocumentFactory` where each subclass (`PDFDocumentFactory`, `WordDocumentFactory`) creates different document types. | A `GUIFactory` that creates both `Button` and `Checkbox` for Windows or Mac. |

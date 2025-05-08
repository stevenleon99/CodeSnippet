## 🔹 Deep Copy vs Move — Conceptual Difference

| Aspect            | **Deep Copy**                                        | **Move (Move Constructor)**                             |
|-------------------|------------------------------------------------------|----------------------------------------------------------|
| **What it does**  | Allocates new memory and copies all content          | Transfers ownership of resources (e.g., pointers)        |
| **Performance**   | **Slower**, especially for large data                | **Faster**, avoids copying by reusing existing memory    |
| **Source state**  | Source remains unchanged, still owns its data        | Source is **emptied** (left in valid but null state)     |
| **When used**     | When copying lvalues                                 | When moving rvalues (temporaries or `std::move(...)`)    |
| **Used in**       | Copy constructor/assignment                          | Move constructor/assignment (`T(T&&)`)                   |

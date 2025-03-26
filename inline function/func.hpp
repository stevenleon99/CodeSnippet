class A {
public:
    A() {};  // Constructor
    ~A() {}; // Destructor

    void doSomething();  // Non-inline function declaration
    inline void doInline();  // Inline function declaration

private:
    int data;
};

#include "func-inl.hpp"  // Include inline function definitions
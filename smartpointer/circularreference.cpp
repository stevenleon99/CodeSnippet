#include <memory>
#include <iostream>

struct B; // Forward declaration

struct A {
    std::shared_ptr<B> b_ptr;
    ~A() { std::cout << "A destroyed\n"; }
};

struct B {
    std::shared_ptr<A> a_ptr;
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b_ptr = b; 
    // A destructor will be called before B destructor
    // A hold a shared pointer reference to B. 
    // Only when A is destroyed, B's reference count can be zero
    // b->a_ptr = a; // CIRCULAR REFERENCE
    
    // Both a and b go out of scope here, but are never destroyed
}
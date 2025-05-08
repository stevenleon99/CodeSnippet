#include <iostream>
#include <memory>
#include <string>

using namespace std;

class myclass {
public:
    int number;
    string name;
    myclass() :
    number(0), name("default") {
        cout << "Constructor called" << endl;
    }
    ~myclass() {
        cout << "Destructor called" << endl;
    }
    void add() {
        number += 1;
    }
};

int main(int argc, char* argv[]) {
    // unique pointer is used for exclusive ownership
    unique_ptr<myclass> p1 = make_unique<myclass>();
    // An rvalue (like a temporary object or a result of an expression) isn't a new type — it's a category of expressions that can only be moved from, not reused.
    // That's what std::move() does — it casts an lvalue (left value: exist on the left side of '=') to an rvalue reference (T&&) so the move constructor or move assignment can be invoked.
    // Instead of making deep copies, moving allows you to transfer ownership of internal resources (like pointers or buffers) — avoiding allocations and data duplication.
    auto p2 = std::move(p1);
    printf("p1 address: %p, p2 address: %p \n", p1.get(), p2.get()); //p1 address: 0000000000000000, p2 address: 00000000006774c0

    // shared pointer is used for shared ownership
    shared_ptr<myclass> sp1 = make_shared<myclass>();
    cout << "sp1: " << sp1->name << "; " << sp1->number << endl;
    sp1->add(); 
    std::shared_ptr<myclass> sp2 = sp1; // shared ownership
    cout << "sp2: " << sp2->name << "; " << sp2->number << endl;
    printf("sp1 address: %p, sp2 address: %p \n", sp1.get(), sp2.get()); // sp1 address: 0000000000681630, sp2 address: 0000000000681630
    
    // weak pointer is used to break circular references
    // weak pointer only observes the object
    // A weak_ptr is recycled (becomes expired) when the last owning shared_ptr is destroyed.
    std::weak_ptr<myclass> wp = sp1; // weak pointer does not affect the reference count
    // convert a weak pointer to a shared pointer
    if (auto sp = wp.lock()) {
        // Use sp safely
    }

    return 0;
}
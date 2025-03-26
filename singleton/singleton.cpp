#include <iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance; 
    Singleton () {
        cout << "create successfully the class singleton and a=" << a << endl;
        a++;
    }
public:
    int a = 1;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) instance = new Singleton();
        return instance;
    }

    void displayNumber(){
        cout << "the class singleton and a=" << a << endl;
    }
};

Singleton* Singleton::instance = nullptr;

int main(int argc, char const *argv[])
{
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    instance1->displayNumber();
    instance2->displayNumber();
    return 0;
}

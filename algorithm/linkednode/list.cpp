#include <iostream>

using namespace std;

struct NodeList {
    int val;
    NodeList *next;
    NodeList(int val): val(val), next(NULL) {}
};


int main(int argc, char const *argv[])
{
    NodeList *head = new NodeList(3);
    delete head;
    return 0;
}

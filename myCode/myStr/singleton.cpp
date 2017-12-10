#include <string>
#include <iostream>
using namespace std;

class singleton {
private:
    static singleton* singletonInst;
    singleton() {};
public:
    static singleton* getInst(void);
};

//singleton* singleton::singletonInst = NULL;
singleton* singleton::singletonInst = new singleton();
singleton* singleton::getInst(void) {
    //if (singletonInst == NULL) {
    //    singletonInst = new singleton;
    //}
    return singletonInst;
}

int main(void) {
    singleton* inst1 = singleton::getInst();
    singleton* inst2 = singleton::getInst();
    singleton* inst3 = singleton::getInst();
    cout << inst1 << endl;
    cout << inst2 << endl;
    cout << inst3 << endl;
}

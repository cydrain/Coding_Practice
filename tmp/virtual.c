#include <iostream>

using namespace std;

typedef void(*Func)(void);

void a() {
    cout << "global a" << endl;
}

class Base {
public:
    virtual void f() {
        cout << "Base::f" << endl;
    }
    virtual void g() {
        cout << "Base::g" << endl;
    }
    virtual void h() {
        cout << "Base::h" << endl;
    }

    void info() {
        int i;
        long* tmp[10];
        long **vtable = tmp;
        Func pFunc = NULL;

        // VTABLE is a table with this structure "long* tmp[10]"
        // the first element in object is the address of VTABLE
        cout << "addr: " << this << endl;
        vtable = (long**)*(long*)this;
        cout << "virtual table addr: " << vtable << endl;
        cout << "1st virtual API's addr: " << (vtable[0]) << endl;
        cout << "2nd virtual API's addr: " << (vtable[1]) << endl;
        cout << "3rd virtual API's addr: " << (vtable[2]) << endl;

        for (i = 0; i <= 2; i++) {
            pFunc = (Func)(vtable[i]);
            cout << (long*)pFunc << endl;
            pFunc();
        }

        cout << endl;
    }
};

class Derived : public Base {
public:
    virtual void f() {
        cout << "Derived::f" << endl;
    }
    virtual void g1() {
        cout << "Derived::g1" << endl;
    }
    virtual void h1() {
        cout << "Derived::h1" << endl;
    }
};

int main(void) {
    int i;
    Func pFunc = NULL;
    Base b, b1;
    Derived d;

    b.info();
    b1.info();
    d.info();

    return 0;
}


#include <iostream>
using namespace std;

void func1(void) {
    int A[5];
    int *B = new int[5];
    cout << "func1: " << A << " " << B << endl;
}
void func2(void) {
    int A[5];
    int *B = new int[5];
    cout << "func2: " << A << " " << B << endl;
    func1();
}
void func3(void) {
    int A[5];
    int *B = new int[5];
    cout << "func3: " << A << " " << B << endl;
    func2();
}

int main(void) {
    func3();
    return 0;
}

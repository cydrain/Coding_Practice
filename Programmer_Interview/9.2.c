#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class CDemo {
    public:
        char* str;
    public:
        CDemo():str(NULL) {};
        CDemo(const CDemo& a) {
            str = new char[strlen(a.str)+1];
            strcpy(str, a.str);
        };
        ~CDemo() {
            if (str) {
                static int i = 0;
                cout << "&CDemo" << i++ << "=" << (int*)this << ",\t";
                cout << "str = " << (int*)str << endl;
                delete[] str;
            }
        };
};

int main(int argc, char** argv) {
    CDemo d1;
    d1.str = new char[32];
    strcpy(d1.str, "trend micro");

    vector<CDemo> *a1 = new vector<CDemo>();
    a1->push_back(d1);
    delete a1;

    return EXIT_SUCCESS;
}


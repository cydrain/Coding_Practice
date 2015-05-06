#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
    char* ptr;
    int len;

public:
    MyString(): ptr(NULL),len(0) {}
    MyString(const char* s);
    MyString(const MyString& other);
    MyString& operator=(MyString& other);
    ~MyString();
    void show();
};

MyString::MyString(const char* s) {
    if (s == NULL) {
        ptr = NULL;
        len = 0;
    } else {
        len = strlen(s);
        ptr = (char*)malloc(len+1);
        if (ptr == NULL) {
            cout << "malloc fail!" << endl;
            exit(1);
        }
        memset(ptr, '\0', len+1);
        strcpy(ptr, s);
    }
    cout << "MyString constructor called!" << endl;
}

MyString::MyString(const MyString& other) {
    if (other.ptr == NULL) {
        ptr = NULL;
        len = 0;
    } else {
        len = other.len;
        ptr = (char*)malloc(len+1);
        if (ptr == NULL) {
            cout << "malloc fail!" << endl;
            exit(1);
        }
        memset(ptr, '\0', len+1);
        strcpy(ptr, other.ptr);
    }
    cout << "MyString copy constructor called!" << endl;
}

MyString& MyString::operator=(MyString& other) {
    if (&other == this) {
        return *this;
    }
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        len = 0;
    }
    if (other.ptr != NULL) {
        len = other.len;
        ptr = (char*)malloc(len+1);
        if (ptr == NULL) {
            cout << "malloc fail!" << endl;
            exit(1);
        }
        memset(ptr, '\0', len+1);
        strcpy(ptr, other.ptr);
    }

    cout << "MyString assignment function called!" << endl;
    return *this;
}

MyString::~MyString() {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
        len = 0;
    }
    cout << "MyString destructor called!" << endl;
}

void MyString::show() {
    cout << "len:" << len << " ptr:" << ptr << endl;
}

int main(void) {
    MyString a("cydrain");
    a.show();
    MyString b(a);
    b.show();
    MyString c("feisiyicl");
    c.show();
    b = c;
    b.show();
    return 0;
}


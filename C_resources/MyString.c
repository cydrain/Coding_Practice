#include <string>
#include <iostream>

using namespace std;

class MyString {
private:
    char *ptr;
    int len;

public:
    MyString():ptr(NULL),len(0) {}
    MyString(const char* s);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);

    void show() {
        cout << "Len:" << len << "  ";
        if (ptr) {
            cout << "Data:" << ptr << endl;
        } else {
            cout << "Data:null" << endl;
        }
    }

    ~MyString() {
        if (ptr != NULL) {
            free (ptr);
            ptr = NULL;
            len = 0;
        }
    }
};

MyString::MyString(const char* s) {
    if (s == NULL) {
        ptr = NULL;
        len = 0;
    } else {
        len = strlen(s);
        ptr = (char*)malloc(sizeof(char) * (len+1));
        if (ptr == NULL) {
            cout << "malloc fail!" << endl;
        }
        memset(ptr, '\0', sizeof(char)*(len+1));
        strcpy(ptr, s);
    }

    cout << "MyString constructor called !" << endl;
}

MyString::MyString(const MyString& other) {
    if (other.ptr == NULL) {
        ptr = NULL;
        len = 0;
    } else {
        ptr = (char*)malloc(sizeof(char) * (other.len+1));
        if (ptr == NULL) {
            cout << "malloc fail!" << endl;
        }
        memset(ptr, '\0', sizeof(char)*(other.len+1));
        strcpy(ptr, other.ptr);
        len = other.len;
    }
            
    cout << "MyString copy constructor called !" << endl;
}

MyString& MyString::operator=(const MyString& other) {
    if (this == &other) return *this;
    if (ptr != NULL) {
        free (ptr);
        ptr = NULL;
        len = 0;
    }
    if (other.ptr == NULL) return *this;

    ptr = (char*)malloc(sizeof(char) * (other.len+1));
    if (ptr == NULL) {
        cout << "malloc fail!" << endl;
    }
    memset(ptr, '\0', sizeof(char)*(other.len+1));
    strcpy(ptr, other.ptr);
    len = other.len;

    cout << "MyString assign operator called !" << endl;
    return *this;
}

int main(void) {
    MyString s1;
    s1.show();
    MyString s2("cydrain");
    s2.show();
    MyString s3("feisiyicl");
    s3.show();
    MyString s4(s2);
    s4.show();
    s4 = s3;
    s4.show();
    return 0;
}

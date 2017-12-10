#include <iostream>
#include <string>
using namespace std;

class myStr {
private:
    char* m_data;
public:
    myStr(const char* str=NULL);
    myStr(const myStr& other);
    myStr& operator=(const myStr& other);
    myStr& operator+(myStr& other);
    ~myStr();
    void show(void);
};

myStr::myStr(const char* str) {
    if (str == NULL) {
        m_data = NULL;
    } else {
        int len = strlen(str);
        m_data = new char[len+1];
        if (m_data == NULL) {
            cout << "Out of memory!" << endl;
        }
        strcpy(m_data, str);
    }
}

myStr::myStr(const myStr& other) {
    if (other.m_data == NULL) {
        m_data = NULL;
    } else {
        int len = strlen(other.m_data);
        m_data = new char[len+1];
        if (m_data == NULL) {
            cout << "Out of memory!" << endl;
        }
        strcpy(m_data, other.m_data);
    }
}

myStr& myStr::operator=(const myStr& other) {
    if (this == &other) {
        return *this;
    }
    if (m_data != NULL) {
        delete[] m_data;
        m_data = NULL;
    }
    if (other.m_data != NULL) {
        int len = strlen(other.m_data);
        m_data = new char[len+1];
        if (m_data == NULL) {
            cout << "Out of memory!" << endl;
        }
        strcpy(m_data, other.m_data);
    }
    return *this;
}

myStr& myStr::operator+(myStr& other) {
    if (other.m_data == NULL) {
        return *this;
    }
    if (this == &other) {
        int len = strlen(m_data);
        char *str = new char[2*len+1];
        if (str == NULL) {
            cout << "Out of memory!" << endl;
        }
        strcpy(str, m_data);
        strcat(str, m_data);
        delete[] m_data;
        m_data = str;
    } else {
        int len = strlen(m_data) + strlen(other.m_data);
        char *str = new char[len+1];
        if (str == NULL) {
            cout << "Out of memory!" << endl;
        }
        strcpy(str, m_data);
        strcat(str, other.m_data);
        delete[] m_data;
        m_data = str;
    }
    return *this;
}

myStr::~myStr() {
    delete[] m_data;
}

void myStr::show() {
    cout << m_data << endl;
}

int main(void) {
    myStr s1("caiyd");
    myStr s2(s1);
    s1.show();
    s2.show();
    myStr s3("cydrain");
    s2 = s3;
    s2.show();
    s3.show();
    s2 = s2 + s3;
    s3 = s3 + s3;
    s2.show();
    s3.show();
    return 0;
}

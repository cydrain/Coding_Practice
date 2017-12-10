#include<iostream>  
using namespace std;  
      
// 定义仅由HasPtr类使用的U_Ptr类，用于封装使用计数和相关指针  
// 这个类的所有成员都是private，我们不希望普通用户使用U_Ptr类，所以它没有任何public成员  
// 将HasPtr类设置为友元，使其成员可以访问U_Ptr的成员  
class U_Ptr {
    friend class HasPtr;
private:
    int *ip;
    size_t use;

private:
    U_Ptr(int *p):ip(p),use(1) {
        cout << "U_Ptr constructor called !" << endl;
    }

    ~U_Ptr() {
        delete ip;
        cout << "U_Ptr destructor called !" << endl;
    }
};  

class HasPtr {  
private:  
    U_Ptr *ptr;   //指向使用计数类U_Ptr  
    int val;  
public:  
    // 构造函数：p是指向已经动态创建的int对象指针  
    HasPtr(int *p, int i):ptr(new U_Ptr(p)),val(i) {
        cout << "HasPtr constructor called ! use = " << ptr->use << endl;
    }
      
    // 复制构造函数：复制成员并将使用计数加1  
    HasPtr(const HasPtr &orig):ptr(orig.ptr),val(orig.val) {
        ++ptr->use;
        cout << "HasPtr copy constructor called ! use = " << ptr->use << endl;
    }
      
    // 赋值操作符  
    //注意，这里赋值操作符在减少做操作数的使用计数之前使rhs的使用技术加1，从而防止自我赋值  
    HasPtr& operator=(const HasPtr& rhs) {
        // 增加右操作数中的使用计数  
        ++rhs.ptr->use;

        // 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象  
        if (--ptr->use == 0) {
            delete ptr->ip;
        }

        ptr = rhs.ptr;
        val = rhs.val;

        cout << "HasPtr assignment constructor called ! use = " << ptr->use << endl;

        return *this;
    }
      
    // 析构函数：如果计数为0，则删除U_Ptr对象  
    ~HasPtr() {
        cout << "HasPtr destructor called ! use = " << ptr->use << endl;
        if (--ptr->use == 0) {
            delete ptr;
        }
    }
      
    // 获取数据成员
    int *get_ptr() const {
        return ptr->ip;
    }
    int get_int() const {
        return val;
    }
      
    // 修改数据成员
    void set_ptr(int *p) const {
        ptr->ip = p;
    }
    void set_int(int i) {
        val = i;
    }
      
    // 返回或修改基础int对象  
    int get_ptr_val() const {
        return *ptr->ip;
    }
    void set_ptr_val(int i) {
        *ptr->ip = i;
    }
};

int main(void) {  
    int *pi = new int(42);
    HasPtr *hpa = new HasPtr(pi, 100);  // 构造函数
    HasPtr *hpb = new HasPtr(*hpa);     // 拷贝构造函数
    HasPtr *hpc = new HasPtr(*hpb);     // 拷贝构造函数
    HasPtr hpd = *hpa;     // 拷贝构造函数

    int *pj = new int(314);
    hpc = new HasPtr(pj, 200);

    cout << hpa->get_ptr_val() << " " << hpb->get_ptr_val() << endl;  
    hpc->set_ptr_val(10000);  
    cout << hpa->get_ptr_val() << " " << hpc->get_ptr_val() << endl;  
    cout << hpa->get_ptr_val() << " " << hpb->get_ptr_val() << endl;  
    hpd.set_ptr_val(10);  
    cout << hpa->get_ptr_val() << " " << hpb->get_ptr_val() << endl;  
    delete hpa;  
    delete hpb;  
    delete hpc;  
    cout << hpd.get_ptr_val() << endl;  
    return 0;  
}


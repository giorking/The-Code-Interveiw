#include <iostream>

using namespace std;

class Byte{
public:
    int val;
    void print() {
        cout << "Byte" << endl;
    }
};

class Int :public Byte{
public:
    long val;
    virtual void print() {
        cout << "int" << endl;
    }
};

class Int64 :public Int{
public:
    long long val;
    virtual void print() {
        cout << "long long" << endl;
    }
};

class tencent{
public:
    tencent(){}
    virtual ~tencent() {}
};

int main(){
    Byte * a = (Byte*)(new Int());
    a->print();
    cout << sizeof(long long) << endl;
    Byte * b = (Byte*)(new Int64());
    b->print();
    cout << sizeof(Int) << endl;
    Int * c = (Int*)(new Int64());
    c->print();
    //cout << sizeof(tencent) << endl;
    return 0;
}

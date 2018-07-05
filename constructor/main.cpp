#include <iostream>

using namespace std;

/**
 * 析构函数
 * 拷贝构造函数
 * 移动构造函数
 * 拷贝赋值 operator=
 * 移动赋值 operator=
 *
 */

class IntCell{
public:
    explicit IntCell(int initialValue = 0){
        storedValue = new int{initialValue};
    }

    int read() const{
        return *storedValue;
    }

    void write(int x){
        *storedValue = x;
    }

private:
    int *storedValue;
};

/**
 * 输出为3个4，可是逻辑上只有a应该是4。
 * 问题在于，默认的拷贝构造复制运算符和拷贝构造函数复制了指针 storedValue。
 * 于是，a.storedValue, b.storedValue, c.storedValue 都指向同一个int量。
 * 这些复制均为浅拷贝，被复制的是这些指针而不是被指向的对象。其次，不太明显
 * 的问题是内存泄露。有a的构造函数初始定位的int型变量依旧定位不变但需要被回收。
 * 由c的构造函数定位的int型变量不在被让任何指针变量引用，它也需要被回收，但我们
 * 不再有指针指向它。
 *
 */
int f(){
    IntCell a{2};
    IntCell b = a;
    IntCell c;

    c = b;
    a.write(4);
    cout << a.read() << endl << b.read() << endl << c.read() << endl;

    return 0;
}

int main()
{
    f();
    return 0;
}

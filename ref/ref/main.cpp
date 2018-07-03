#include <iostream>

using namespace std;

// 左值引用和右值引用(C++11)
/**
 * 左值是可以放在赋值号左边可以被赋值的值；左值必须要在内存中有实体。
 * 右值挡在赋值号右边取出值赋给其他变量的值；右值可以在内存也可以在CPU寄存器。
 *
 * 一个对象被用作右值时，使用的是他的内容（值），被当作左值时，使用的是他的地址。
 *
 * 左值引用：type &引用名 = 左值表达式
 * 右值引用：type &&引用名 = 右值表达式
 *
 */
int main()
{
    cout << "------引用左值-------" << endl;
    int a = 5;
    int &add_a(a);

    cout << "a == " << a << "  " << "&a == " << &a << endl;
    cout << "add_a == " << add_a << "  " << "&add_a == " << &add_a <<endl;
    cout << "------------------------" <<endl;

    cout << "-----引用右值-------" << endl;
    int b = 10;
    int &&add_b(b+1);  //右值引用，引用b+1的值，放到add_b的地址中，所以add_b为新的地址。
    cout << "b == " << b << "  " << "&b == " << &b << endl;
    cout << "add_b == " << add_b << "  " << "&add_b = " << &add_b << endl;
    add_b++;
    cout << "add_b++ == " << add_b << "  " << "&add_b++ == " << &add_b << endl;
    cout << "--------------------------" << endl;

    return 0;
}

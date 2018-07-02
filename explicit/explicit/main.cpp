#include <iostream>

using namespace std;

/**
 * C++提供的关键字explicit只能用于修饰一个参数的类构造函数。
 * 他的作用是表明该构造函数是显示的，而implicit是隐藏的。
 * 类的构造函数默认情况下是implicit的。
 *
 */

 class CxString{ // 没有使用explicit关键字的类声明，即默认为隐式声明
public:
    char *_pstr;
    int _size;

    CxString(int size){
        _size = size;  //string的预设大小
        _pstr = malloc(size + 1);  // 分配string的内存
        memset(_pstr,0,size + 1);
    }

    CxString(const char *p){
        int size = strlen(p);
        _pstr = malloc(size + 1); //分配string的内存
        strcpy(_pstr,p);  //复制字符串
        _size = strlen(_pstr);
    }

 };

//上方主类调用
CxString string1(24);  //这样是可以的，为CxString预分配24字节大小的内存
CxString string2 = 10; //这样是可以的，为CxString与分配10字节大小的内存
CxString string3; //这样是不行的，没有合适的构造器
CxString string4("aaa"); //这样是可以的，调用CxString(const char*p)
CxString string5 = "bbb"; //这样是可以的，调用CxString(const char*p)
CxString string6 = 'c'; //这样是可以的，实际调用CxString(int size), 且size等于'c'的ascii码
string1 = 2; // 这样是可以的，为CxString预分配2字节大小的内存
string2 = 3; // 这样是可以的，为CxString预分配3字节大小的内存
string3 = string1; // 这样是可以的，至少编译是没有问题的，但是如果析构函数里面有free释放_pstr内存指针的时候可能会报错，完整的代码必须重载运算符"=",并在其中处理内存释放

/**
 * 上面的代码中， "CxString string2 = 10;" 可以的原因为：在C++中，如果构造函数只有一个参数时，
 * 那么在编译的时候就会有一个缺省的转换操作：将该构造函数对应数据类型的数据转换为该类对象，也就是
 * 说"CxString string2 = 10;"这段代码，编译器自动将整型转换为CxString类对象，实际上等同于下面的操作：
 *
 * CxString string2(10);
 * 或
 * CxString temp(2);
 * CxString string2 = temp;
 *
 */

 // 上面的代码中的_size代表的是字符串内存分配的大小，那么调用的第二句"CxString string2 = 10" 或 "CxString string6 = 'c';"
 // 就显得不伦不类，容易让人疑惑，有什么办法阻止这种用法呢？答案就是使用explicit关键字。
 // 修改为下述代码：

 class CxString{  // 使用关键字explicit的类声明，显示转换
 public:
    char *_pstr;
    int _size;

    explicit CxString(int size){
        _size = size;
        _pstr = malloc(size + 1);  // 分配string的内存
        memset(_pstr,0,size + 1);
    }

    CxString(const char *p){
        int size = strlen(p);
        _pstr = malloc(size + 1); //分配string的内存
        strcpy(_pstr,p);  //复制字符串
        _size = strlen(_pstr);
    }
 };

//上述程序调用
CxString string1(24);  //这样是可以的，为CxString预分配24字节大小的内存
CxString string2 = 10; //这样是不行的
CxString string3; //这样是不行的，没有合适的构造器
CxString string4("aaa"); //这样是可以的，调用CxString(const char*p)
CxString string5 = "bbb"; //这样是可以的，调用CxString(const char*p)
CxString string6 = 'c'; //这样是不行的，因为取消了隐式转换
string1 = 2; // 这样是不行的，因为取消了隐式转换
string2 = 3; // 这样是不行的，因为取消了隐式转换
string3 = string1; // 这样是不行的，因为取消了隐式转换，除非类实现了操作符"="的重载。

// 上述说过，explicit关键字只对一个参数的类构造函数有效，如果类构造函数参数大于或等于两个时，
// 是不会产生隐式转换的，所以explicit关键字也就无效了。


// 但是，也有一个例外，就是当除了第一个参数以外的其他参数都有默认值的时候，explicit关键字依然有效，此时
// 当调用构造函数时之传入一个参数，等效于只有一个参数的类构造函数。

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

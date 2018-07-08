#include <iostream>

using namespace std;

// 五大函数，参考"cinstructor"

class IntCell
{
public:
    explicit IntCell(int initialValue = 0){
        storedValue = new int{initialValue};
    }

    ~IntCell(){
        delete storedValue;   // 析构函数
    }

    IntCell(const IntCell & rhs){
        storedValue = new Int{*rhs.storedValue};  //拷贝构造函数
    }

    IntCell(IntCell &&rhs) : storedValue{rhs.storedValue}{  // 移动构造函数
        rhs.storedValue = nullptr;
    }

    IntCell & operator= (const IntCell &rhs)   // 拷贝赋值
    {
        if(this != &rhs)
            *storedValue = *rhs.storedValue;

        return *this;
    }

    IntCell & operator= (IntCell &&rhs){   //移动赋值
        swap(storedValue,rhs.storedValue);

        return *this;
    }

    int read() const{
        return *storedValue;
    }

    void write(int x){
     *storedValue = x;
    }

private :
    int *storedValue;
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

#include <iostream>

using namespace std;

// ��������ο�"cinstructor"

class IntCell
{
public:
    explicit IntCell(int initialValue = 0){
        storedValue = new int{initialValue};
    }

    ~IntCell(){
        delete storedValue;   // ��������
    }

    IntCell(const IntCell & rhs){
        storedValue = new Int{*rhs.storedValue};  //�������캯��
    }

    IntCell(IntCell &&rhs) : storedValue{rhs.storedValue}{  // �ƶ����캯��
        rhs.storedValue = nullptr;
    }

    IntCell & operator= (const IntCell &rhs)   // ������ֵ
    {
        if(this != &rhs)
            *storedValue = *rhs.storedValue;

        return *this;
    }

    IntCell & operator= (IntCell &&rhs){   //�ƶ���ֵ
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

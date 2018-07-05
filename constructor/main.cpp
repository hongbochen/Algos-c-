#include <iostream>

using namespace std;

/**
 * ��������
 * �������캯��
 * �ƶ����캯��
 * ������ֵ operator=
 * �ƶ���ֵ operator=
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
 * ���Ϊ3��4�������߼���ֻ��aӦ����4��
 * �������ڣ�Ĭ�ϵĿ������츴��������Ϳ������캯��������ָ�� storedValue��
 * ���ǣ�a.storedValue, b.storedValue, c.storedValue ��ָ��ͬһ��int����
 * ��Щ���ƾ�Ϊǳ�����������Ƶ�����Щָ������Ǳ�ָ��Ķ�����Σ���̫����
 * ���������ڴ�й¶����a�Ĺ��캯����ʼ��λ��int�ͱ������ɶ�λ���䵫��Ҫ�����ա�
 * ��c�Ĺ��캯����λ��int�ͱ������ڱ����κ�ָ��������ã���Ҳ��Ҫ�����գ�������
 * ������ָ��ָ������
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

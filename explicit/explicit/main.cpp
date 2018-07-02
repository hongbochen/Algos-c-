#include <iostream>

using namespace std;

/**
 * C++�ṩ�Ĺؼ���explicitֻ����������һ���������๹�캯����
 * ���������Ǳ����ù��캯������ʾ�ģ���implicit�����صġ�
 * ��Ĺ��캯��Ĭ���������implicit�ġ�
 *
 */

 class CxString{ // û��ʹ��explicit�ؼ��ֵ�����������Ĭ��Ϊ��ʽ����
public:
    char *_pstr;
    int _size;

    CxString(int size){
        _size = size;  //string��Ԥ���С
        _pstr = malloc(size + 1);  // ����string���ڴ�
        memset(_pstr,0,size + 1);
    }

    CxString(const char *p){
        int size = strlen(p);
        _pstr = malloc(size + 1); //����string���ڴ�
        strcpy(_pstr,p);  //�����ַ���
        _size = strlen(_pstr);
    }

 };

//�Ϸ��������
CxString string1(24);  //�����ǿ��Եģ�ΪCxStringԤ����24�ֽڴ�С���ڴ�
CxString string2 = 10; //�����ǿ��Եģ�ΪCxString�����10�ֽڴ�С���ڴ�
CxString string3; //�����ǲ��еģ�û�к��ʵĹ�����
CxString string4("aaa"); //�����ǿ��Եģ�����CxString(const char*p)
CxString string5 = "bbb"; //�����ǿ��Եģ�����CxString(const char*p)
CxString string6 = 'c'; //�����ǿ��Եģ�ʵ�ʵ���CxString(int size), ��size����'c'��ascii��
string1 = 2; // �����ǿ��Եģ�ΪCxStringԤ����2�ֽڴ�С���ڴ�
string2 = 3; // �����ǿ��Եģ�ΪCxStringԤ����3�ֽڴ�С���ڴ�
string3 = string1; // �����ǿ��Եģ����ٱ�����û������ģ����������������������free�ͷ�_pstr�ڴ�ָ���ʱ����ܻᱨ�������Ĵ���������������"=",�������д����ڴ��ͷ�

/**
 * ����Ĵ����У� "CxString string2 = 10;" ���Ե�ԭ��Ϊ����C++�У�������캯��ֻ��һ������ʱ��
 * ��ô�ڱ����ʱ��ͻ���һ��ȱʡ��ת�����������ù��캯����Ӧ�������͵�����ת��Ϊ�������Ҳ����
 * ˵"CxString string2 = 10;"��δ��룬�������Զ�������ת��ΪCxString�����ʵ���ϵ�ͬ������Ĳ�����
 *
 * CxString string2(10);
 * ��
 * CxString temp(2);
 * CxString string2 = temp;
 *
 */

 // ����Ĵ����е�_size��������ַ����ڴ����Ĵ�С����ô���õĵڶ���"CxString string2 = 10" �� "CxString string6 = 'c';"
 // ���Եò��ײ��࣬���������ɻ���ʲô�취��ֹ�����÷��أ��𰸾���ʹ��explicit�ؼ��֡�
 // �޸�Ϊ�������룺

 class CxString{  // ʹ�ùؼ���explicit������������ʾת��
 public:
    char *_pstr;
    int _size;

    explicit CxString(int size){
        _size = size;
        _pstr = malloc(size + 1);  // ����string���ڴ�
        memset(_pstr,0,size + 1);
    }

    CxString(const char *p){
        int size = strlen(p);
        _pstr = malloc(size + 1); //����string���ڴ�
        strcpy(_pstr,p);  //�����ַ���
        _size = strlen(_pstr);
    }
 };

//�����������
CxString string1(24);  //�����ǿ��Եģ�ΪCxStringԤ����24�ֽڴ�С���ڴ�
CxString string2 = 10; //�����ǲ��е�
CxString string3; //�����ǲ��еģ�û�к��ʵĹ�����
CxString string4("aaa"); //�����ǿ��Եģ�����CxString(const char*p)
CxString string5 = "bbb"; //�����ǿ��Եģ�����CxString(const char*p)
CxString string6 = 'c'; //�����ǲ��еģ���Ϊȡ������ʽת��
string1 = 2; // �����ǲ��еģ���Ϊȡ������ʽת��
string2 = 3; // �����ǲ��еģ���Ϊȡ������ʽת��
string3 = string1; // �����ǲ��еģ���Ϊȡ������ʽת����������ʵ���˲�����"="�����ء�

// ����˵����explicit�ؼ���ֻ��һ���������๹�캯����Ч������๹�캯���������ڻ��������ʱ��
// �ǲ��������ʽת���ģ�����explicit�ؼ���Ҳ����Ч�ˡ�


// ���ǣ�Ҳ��һ�����⣬���ǵ����˵�һ�����������������������Ĭ��ֵ��ʱ��explicit�ؼ�����Ȼ��Ч����ʱ
// �����ù��캯��ʱ֮����һ����������Ч��ֻ��һ���������๹�캯����

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

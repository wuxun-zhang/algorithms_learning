#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct base {
	base() :mem(123) {}
protected:
	int mem;
};

struct derived :public base {
	derived() = default;
	derived(int i) :mem(i) {}
	int get_mem()
	{
		return mem;
	}
protected:
	int mem;	// ��ֱ�ӻ�����ӻ������ı������Ȳ��ҵ�ǰ��������δ�ҵ�������㣨���ࣩ���������
};

//void main()
//{
//	/*derived A(233);
//	std::cout << A.get_mem() << std::endl;*/
//
//	const char* a = "asdhcnhdb";
//	vector<char> b(a, a+9);
//	string c(b.cbegin(), b.cend());
//	cout << c << endl;
//	//c.resize(15, '*');
//	//cout << c << endl;
//	//c.insert(2, 5, '!');
//	//cout << c << endl;
//	int idx = c.find('dh');
//	//c.erase(c.begin() + idx, c.end());
//	cout << idx << endl;
//
//	while (1)
//	{
//		string input;
//		cout << "����һ���ַ�����" << endl;
//		cin >> input;
//		cout << "������Ҫ���ҵ����ַ�����";
//		string substr;
//		cin >> substr;
//		int idx = input.rfind(substr);	// �����������������ص�һ��ƥ����ַ��������ַ�λ��
//		cout << "����" << substr << "��" << input << "��������" << idx << endl;
//	}
//}

#include<iostream>
#include<string>
using namespace std;

// test rebase, currently in branch-master

class bitOps {
public:
	// #1. 获取int型的最大值
	int getMaxInt_v1() {
		return (1 << 31) - 1;
	}
	int getMaxInt_v2() {
		return ~(1 << 31);
	}
	// 不支持，结果错误
	int getMaxInt_v3() {
		return (1 << -1) - 1;
	}

	// #2. 获取int型最小值
	// 不支持，结果不对
	int getMinInt_v1() {
		return 1 << -1;
	}
	int getMinInt_v2() {
		return 1 << 31;
	}

	long getMaxLong_v1() {
		return ((unsigned long)-1) >> 1;
	}
	long getMinLong() {
		return ((long)1 << 127) - 1;
	}

	bool isOddNumber(int n) {
		return (n & 1) == 1;
	}

	// 交换两个数的值，不用临时变量
	void mySwap(int *a, int *b) {
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	// 获取绝对值
	int getAbs(int n) {
		return (n ^ (n >> 31)) - (n >> 31);
	}

	// 判断一个数是不是2的幂
	bool isPower2(int n) {
		return (n > 0) ? (n&(n - 1)) == 0 : false;
	}

	// 对2的N次方取余
	int ModOfPower2(int m, int n) {
		return m&(n - 1);
	}

	// 从低位到高位，取n得第m位
	int getBitM(int n, int m) {
		return (n >> (m - 1)) & 1;
	}

	// 从低位到高位，将n的第m位置1
	int setBitM(int n, int m) {
		return n | (1 << (m - 1));
	}

	// 从低位到高位，将n的第m位置零
	int resetBitM(int n, int m) {
		return n&(~(1 << (m - 1)));
	}
private:

};

int main(void) {
	int n = 8;
	bitOps op;
	cout << "Maximum of Int " << " is " << op.getMaxInt_v1() << endl;
	cout << "Minimum of Int " << " is " << op.getMinInt_v2() << endl;
	cout << "abs of "<<n<<" is "<<op.getAbs(n) << endl;
	cout << n << (op.isPower2(n)?" is":" is not") << " a power of 2" << endl;
}

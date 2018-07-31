#include<iostream>
using namespace std;

int mysign(int x){
    return (x>0) ? 1:-1;
}

// 翻转32位有符号整数
int reverseInteger(int x){
    long long result = 0;
    int sign = mysign(x);
    x *= sign;
    while(x>0){
        result = 10*result + (x%10);
        x /= 10;
    }
    result *= sign;
    if(result > (1<<31)-1 || result < -(1<<31)){
        result = 0;
    }
    return result&0xffffffff;
}

int main(void){
    int num;
    while(cin>>num){
        cout<<reverseInteger(num)<<endl;
    }
    return 0;
}
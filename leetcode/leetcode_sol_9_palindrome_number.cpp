#include<iostream>
#include<vector>
using namespace std;
// 判断输入的整型数是否满足回文结构，如121, 1661
bool isPalindrom(int x){
    if(x<0){
        return false;
    }
    if(x>=0 && x<=9){
        return true;
    } 
    int t = x;
    int result = 0;
    while(t>0){
        result = 10*result + t%10;
        t /= 10;
    }
    if(result == x){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    int x;
    while(cin>>x){
        cout<<(isPalindrom(x)?"true" : "false")<<endl;
    }
    return 0;
}
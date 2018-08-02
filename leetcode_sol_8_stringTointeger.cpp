#include<iostream>
#include<string>
#include<stdint.h>
using namespace std;

// 算法复杂度为 O(n)
int myAtoi(string& str){
    if(str.empty()){
        return 0;
    }
    string::size_type N = str.size(); 
    int i;
    for(i=0; i<N;i++){
        if(str[i] != ' '){
            break;
        }
    }
    bool sign = true;
    long long result = 0;
    if(i == N-1 && (str[i]<'0' || str[i]>'9')){
        return 0;
    }
    else if((str[i] != '-' && str[i] != '+') && (str[i]>'9' || str[i]<'0')){
        return 0;
    }
    else{
        for(int k=i;k<N;k++){
            if(str[k] == '-' || str[k] == '+'){
                sign = str[i]=='-' ? false:true;
                continue;
            }
            if(str[k]>'9' || str[k]<'0'){
                break;
            }
            result = 10*result + str[k]-'0';
        }
    }

    result = sign ? result : (-result);
    if(result > INT32_MAX)
        result = INT32_MAX;
    if(result < INT32_MIN)
        result = INT32_MIN;
    return result & 0xffffffff;
}

int main(void){
    std::string in;
    while(cin>>in){
        std::cout<<myAtoi(in)<<std::endl;
    }
    return 0;
}
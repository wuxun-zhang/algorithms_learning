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
    if(i == N){
        return 0;
    }
    int sign = 1;
    int result = 0;
    if(str[i] == '+'){
        i++;
    }else if(str[i] == '-'){
        sign = -1;
        i++;
    }
    // 应该先做i<N的判断，避免出现数组越界访问的情况
    while(i<N && str[i]<='9' && str[i]>='0'){
        int digit = str[i] - '0';
        // 考虑到result的范围也是[INT32_min, INT32_max]，因此先做是否溢出的判断
        if(result > (INT32_MAX - digit)/10){
            if(sign == -1){
                return INT32_MIN;
            }else{
                return INT32_MAX;
            }
        }
        result = result*10 + digit;
        i++;
    }
    return result*sign;
}


class Solution{
public:
    int myAtoi_v1(string& str){
        long long int result = 0;
        int indicator = 1;

        int i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
            
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT32_MAX) return INT32_MAX;
            if(result*indicator <= INT32_MIN) return INT32_MIN;                
        }
            
        return result*indicator;
    }

    int myAtoi_v2(string& str){
        int result = 0;
        int sign = 1;
        int i = 0;
        int digit;
        while(str[i] == ' ' && i < str.size()) {
            i++;
        }
        if(i == str.size()) {
            return result;
        }
        if(str[i] == '+') {
            i++;
        }
        else if(str[i] == '-') {
            sign = -1;
            i++;
        }
        
        while(str[i] >= '0' && str[i] <= '9' && i < str.size()) {
            digit = str[i] - '0';
            if(result > (INT32_MAX - digit) / 10) {
                if(sign > 0) {
                    return INT32_MAX;
                }
                else {
                    return INT32_MIN;
                }
            }
            result = result * 10 + digit;
            i++;
        }
        return result*sign;
    }
};

int main(void){
    std::string in;
    Solution sol;
    while(cin>>in){
        std::cout<<myAtoi(in)<<std::endl;
    }
    return 0;
}


#include<iostream>
// #include<vector>
#include<stack>
using namespace std;


class _MIN_STACK_ {
public:
    // constructor 
    // _MIN_STACK_(void): min_val(INT32_MAX){

    // }

    void push(int value) {
        // stack_.push_back(value);
        s_data.push(value);
        // find the minimum value
        if(s_min.empty() || s_min.top()>value)
            s_min.push(value);
        else
            s_min.push(s_min.top());
    }
    void pop() {
        //assert(s_data.size()>0 && s_min.size()>0);
        s_data.pop();
        s_min.pop();
    }
    int top() {
       //assert(s_data.size()>0);
       return s_data.top();
    }

    // return the minimum value of stack
    int min() {
        //assert(s_min.size()>0);
        return s_min.top();
    }

    int get_size(void) const{
        return s_data.size();
    }

private:
	// vector<int> stack_;
    stack<int> s_data;
    stack<int> s_min;
    int min_val;
};

// int main(){
// 	_MIN_STACK_ minStack;
//     cout<<"The capcaity of stack is "<<minStack.get_size()<<endl;
// 	minStack.push(11);
// 	minStack.push(2);
// 	minStack.push(20);
// 	minStack.push(4);
//     cout<<"The capcaity of stack is "<<minStack.get_size()<<endl;

// 	// print the stack
// 	// minStack.printStack();

// 	minStack.pop();

// 	// minStack.printStack();

// 	cout<<"The top of the stack is "<<minStack.top()<<endl;

// 	cout<<"The minimum value of the stack is "<<minStack.min()<<endl;

// 	return 0;
// }
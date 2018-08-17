// 用两个栈实现队列的功能，元素先进先出（FIFO）
#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:

    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        // 若stack2中存在元素，则直接弹出栈顶的元素
        if(!stack2.empty()){
            int top = stack2.top();
            stack2.pop();
            return top;
        }
        while(!stack1.empty()){
            int top = stack1.top();
            stack1.pop();
            stack2.push(top);
        }
        if(stack2.empty()){
            throw exception();
        }
        int pop_node = stack2.top();
        stack2.pop();
        return pop_node;
    }

private:
    // stack1：用于存放push进的数据，一旦需要pop，则需要先把数据依次放进stack2中，并把最先存放进stack1的数据pop出去 
    stack<int> stack1;
    stack<int> stack2;
};

int main(void){
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"pop an element from s: "<<s.pop()<<endl;
    cout<<"pop an element from s: "<<s.pop()<<endl;
    s.push(4);
    cout<<"pop an element from s: "<<s.pop()<<endl;
    s.push(5);
    cout<<"pop an element from s: "<<s.pop()<<endl;
    cout<<"pop an element from s: "<<s.pop()<<endl;

    return 0;
}

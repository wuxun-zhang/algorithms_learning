#include<iostream>
#include<string>
#include<stack>
using namespace std;

namespace Prefix_Infix_Suffix{

bool isNumber(char s) {
	    string opers = "+-*/()";
	    for (int i = 0; i < opers.size(); i++) {
	        if (s == opers.at(i)) {
	            return false;
	        }
	    }
	    return true;
}

// determine the priorit between two operators
bool isPriorityLow(char currOper, char topOper) {
	    if (currOper == '+' || currOper == '-') {
	        if (topOper == '*' || topOper == '/' || topOper == '+' || topOper == '-') {
	            return true;
	        }
	    }
	    if (currOper == '*' || currOper == '/') {
	        if (topOper == '*' || topOper == '/') {
	            return true;
	        }
	    }
	    return false;
}

namespace Infix_to_Suffix{

	// when priority of curOps lower than that of stack's topOps, topOps poped will be
	// add to the tail of suffix expressions.
	// keep comparing, until curOps has higher priority than that of the stack's topOps
	// s: postfix expressions
	void loopPushOperator(string& s, char oper, stack<char>& operators) {
	    if (operators.size() > 0 && isPriorityLow(oper, operators.top())) {
	        s += operators.top();
	        operators.pop();
	        loopPushOperator(s, oper, operators);
	    }
	    return;
	}

	void handleOperator(string& s, char oper,  stack<char>& operators) {
	    switch (oper) {
	    case '+':
	    case '-':
	    case '*':
	    case '/':
	        // operators stack is empty
	        if (operators.size() <= 0) {
	            operators.push(oper);
	        
	        } else if (isPriorityLow(oper, operators.top())) {
	            loopPushOperator(s, oper, operators);
	            operators.push(oper);
	        } else {
	            operators.push(oper);
	        }
	        break;
	    case '(':
	        operators.push(oper);
	        break;
	    case ')':
	        while (operators.top() != '(') {
	            s += operators.top();
	            operators.pop();
	        }
	        operators.pop();
	        break;
	    default:
	        break;
	    }
	}

	// s: infix expressions
	string InfixToSuffix(string& s) {
	    stack<char> operators;
	    string suffix; 

	    for (int i = 0; i < s.size(); i++) {
	        if (isNumber(s.at(i))) {
	            suffix += s.at(i);
	        }
	        else {
	            handleOperator(suffix, s.at(i), operators);
	        }
	    }

	    if (suffix.size() > 0) {
	        while (operators.size() > 0) {
	            suffix += operators.top();
	            operators.pop();
	        }
	        return suffix;
	    } else {
	        return "";
	    }
 	}

 	// 
 	void CalculateResult( char oper, stack<int>& tmpStack) {
	    if (tmpStack.size() < 2) {
	        return;
	    }
	    int secondVal = tmpStack.top();
	    tmpStack.pop();
	    int firstVal = tmpStack.top();
	    tmpStack.pop();

	    int result = 0;
	    switch (oper) {
	    case '+':
	        result = firstVal + secondVal;
	        break;
	    case '-':
	        result = firstVal - secondVal;
	        break;
	    case '*':
	        result = firstVal * secondVal;
	        break;
	    case '/':
	        result = firstVal / secondVal;
	        break;
	    default:
	        break;
	    }

	    tmpStack.push(result);
	}

	float getResultUseSuffix(string& s) {
	    if (s.size() <= 0) {
	        return 0;
	    }

	    stack<int> tmpStack;
	    for (int i = 0; i < s.size(); i++) {
	        if (isNumber(s.at(i))) {
	            tmpStack.push(s.at(i) - '0');
	        } else {
	            CalculateResult(s.at(i), tmpStack);
	        }
	    }
	    return tmpStack.top();
	}

} // namespace Infix_to_Suffix

namespace Infix_to_Prefix{



} // namespace Infix_to_Prefix


} // namespace Prefix_Infix_Suffix

int main(void){
	string infix;
	cin>>infix;
	cout<<"infix: "<<infix<<endl;
	string suffix = Prefix_Infix_Suffix::Infix_to_Suffix::InfixToSuffix(infix);
	cout<<"suffix: "<<suffix<<endl;
	float result = Prefix_Infix_Suffix::Infix_to_Suffix::getResultUseSuffix(suffix);
	cout<<"result = "<<result<<endl;
	return 0;
}

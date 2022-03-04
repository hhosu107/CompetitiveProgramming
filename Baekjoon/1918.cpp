#include<bits/stdc++.h>
using namespace std;
/* infix to postfix:
1. op == '(': push.
2. op == ')': pop until '('. popped characters except '(' will be written.
3. op == '+', '-': pop until '('. Do not pop '(', write others in popped order, push.
4. op == '*', '-': pop until '+', '-', '('. Do not pop triggered ones, write others in popped order, push.
5. operands: just write.
*/

string inToPost(string fig) {
    string result = "";
    stack<char> operators;
    for (char x: fig) {
        if (x == '(') operators.push(x);
        else if (x == ')') {
            while (!operators.empty()) {
                char op = operators.top();
                operators.pop();
                if (op == '(')
                    break;
                result += op;
            }
        }
        else if (x == '*' || x == '/') {
            while (!operators.empty()) {
                char op = operators.top();
                if (op == '+' || op == '-' || op == '('){
                    break;
                }
                operators.pop();
                result += op;
            }
            operators.push(x);
        } else if (x == '+' || x == '-') {
            while (!operators.empty()) {
                char op = operators.top();
                if (op == '(')
                    break;
                operators.pop();
                result += op;
            }
            operators.push(x);
        } else result += x;
    }
    while(!operators.empty()) {
        char op = operators.top();
        operators.pop();
        result += op;
    }
    return result;
}

int main () {
    string fig;
    cin >> fig;
    cout << inToPost(fig) << endl;
    return 0;
}
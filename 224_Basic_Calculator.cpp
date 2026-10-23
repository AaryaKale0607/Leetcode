#include<string>
#include<stack>
using namespace std ;
class Solution {
public:
    int calculate(string s) {
           stack<long long> st;
        long long result = 0;
        long long number = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                number = number * 10 + (ch - '0');
            }
            else if (ch == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            }
            else if (ch == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            }
            else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }
            else if (ch == ')') {
                result += sign * number;
                number = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }
        }

        result += sign * number;

        return static_cast<int>(result);
    }
};
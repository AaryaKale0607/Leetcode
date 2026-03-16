#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;

        for(auto e : s)
        {
            if(e != 'c')
            {
                stk.push(e);
            }
            else
            {
                if(stk.size() < 2 || stk.top() != 'b')
                    return false;
                stk.pop();

                if(stk.top() != 'a')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
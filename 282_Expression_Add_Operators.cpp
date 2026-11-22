#include<vector>
#include<string>
using namespace std ;
class Solution {
public:
    vector<string> ans;

    void backtrack(string num, int target, int index,
                   long long currentValue,
                   long long lastOperand,
                   string expression) {

        // All digits have been used
        if (index == num.size()) {
            if (currentValue == target) {
                ans.push_back(expression);
            }
            return;
        }

        long long number = 0;

        // Try different lengths for the next operand
        for (int i = index; i < num.size(); i++) {

            // Avoid numbers with leading zeros
            if (i > index && num[index] == '0') {
                break;
            }

            number = number * 10 + (num[i] - '0');

            string part = num.substr(index, i - index + 1);

            // First operand: no operator needed
            if (index == 0) {
                backtrack(num, target, i + 1,
                          number, number, part);
            }
            else {

                // Addition
                backtrack(num, target, i + 1,
                          currentValue + number,
                          number,
                          expression + "+" + part);

                // Subtraction
                backtrack(num, target, i + 1,
                          currentValue - number,
                          -number,
                          expression + "-" + part);

                // Multiplication
                backtrack(num, target, i + 1,
                          currentValue - lastOperand
                              + lastOperand * number,
                          lastOperand * number,
                          expression + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        ans.clear();

        backtrack(num, target, 0, 0, 0, "");

        return ans;
    }
};

#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    
    vector<int> diffWaysToCompute(string expression) {
        
        // Return previously calculated results
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> ans;

        // Try every operator as a dividing point
        for (int i = 0; i < expression.size(); i++) {

            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {

                // Divide expression into left and right parts
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                // Calculate all possible results
                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);

                // Combine both results
                for (int l : leftResults) {
                    for (int r : rightResults) {

                        if (op == '+') {
                            ans.push_back(l + r);
                        }
                        else if (op == '-') {
                            ans.push_back(l - r);
                        }
                        else {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operator exists, expression is a number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        memo[expression] = ans;

        return ans;
    }
};
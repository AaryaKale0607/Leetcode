#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     
        int xorAll = 0;

        // Step 1: XOR all elements
        for (int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find the rightmost set bit safely
        long long diffBit = (long long)xorAll & (-(long long)xorAll);

        int num1 = 0;
        int num2 = 0;

        // Step 3: Divide numbers into two groups
        for (int num : nums) {

            if ((long long)num & diffBit) {
                num1 ^= num;
            }
            else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};
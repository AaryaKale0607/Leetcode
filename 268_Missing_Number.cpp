#include <vector>
using namespace std ;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
           int ans = nums.size();

        // XOR all indices and array elements
        for (int i = 0; i < nums.size(); i++) {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans; 
    }
};
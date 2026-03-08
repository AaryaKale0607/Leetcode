#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int ans_i = 0;
        for(int i =0 ; i<n ; i++)
        {
            ans[ans_i]=nums[i];
            ans[ans_i + 1]=nums[i+n];
            ans_i+=2;
        }
        return ans;
    }
};
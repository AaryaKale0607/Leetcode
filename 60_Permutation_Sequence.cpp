#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
          vector<int> nums;
        int fact = 1;

        for(int i = 1; i < n; i++)
            fact *= i;

        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        k--; // Convert to 0-based index

        string ans = "";

        while(true) {
            ans += to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));

            if(nums.empty())
                break;

            k %= fact;
            fact /= nums.size();
        }

        return ans;
    }
};
#include <vector>
#include <unordered_map>
#include <algorithm>                                            

using namespace std;


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        if (n < 3) return false;
        
        unordered_map<int, int> um;
        
        // Store value and its index in hash table
        for (int i = 0; i < n; i++) {
            um[arr[i]] = i;
        }
        
        // Find peak element
        int peak = max_element(arr.begin(), arr.end()) - arr.begin();
        
        // Peak cannot be first or last
        if (peak == 0 || peak == n - 1)
            return false;
        
        // Check strictly increasing part
        for (int i = 0; i < peak; i++) {
            if (arr[i] >= arr[i + 1])
                return false;
        }
        
        // Check strictly decreasing part
        for (int i = peak; i < n - 1; i++) {
            if (arr[i] <= arr[i + 1])
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int i = 0;

        // climb up
        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        // peak can't be first or last
        if (i == 0 || i == n - 1) return false;

        // walk down
        while (i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};
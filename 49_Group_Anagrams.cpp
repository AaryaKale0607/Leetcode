#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string , vector<string>> um;

        for(int i = 0 ; i < strs.size();i++)
        {
            string temp = strs[i];
            sort(temp.begin() , temp.end());

            um[temp].push_back(strs[i]);
        }
         vector<vector<string>> result;

        for(auto &it : um)
        {
            result.push_back(it.second);
        }

        return result;
    }
};
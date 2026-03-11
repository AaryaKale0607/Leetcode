#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int  i = 0 , j = 0;

        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
            i++;
            j++;
        }
        return i == s.size();
    }
};

// int cnt = 0 ;
// int sz1 = s.size();
// int sz2 = t.size();

// int i = 0 , j = 0;
// if(sz2 < sz1)
// return false;
// while(i < sz1 && j < sz2)
// {
//     if(s[i]==t[j])
//     {
//         i++;
//         j++;
//         cnt++;
//     }
//     else
//     {
//         j++;
//     }
// }
// if(sz1==cnt)
// return true;
// else 
// return false;


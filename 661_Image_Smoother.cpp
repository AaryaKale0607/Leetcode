#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for(int r = 0 ;  r < rows ; r++)
        {
            for(int c = 0 ; c < cols ; c++)
            {
                int sum = 0;
                int cnt = 0;

                for(int i = max(0 , r - 1) ; i <= min(rows - 1, r + 1) ; i++)
                {
                    for(int j = max(0 , c - 1) ; j <= min(cols - 1 , c + 1) ; j++)
                    {
                        sum += img[i][j];
                        cnt++;
                    }
                }
                result[r][c] = sum / cnt;
            }
        }
        return result;
    }
};
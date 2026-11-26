#include<vector>
#include<cmath>
using namespace std ;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
          int m = board.size();
        int n = board[0].size();

        // All 8 possible directions
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int live = 0;

                // Count live neighbours
                for (int k = 0; k < 8; k++) {

                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m &&
                        y >= 0 && y < n &&
                        abs(board[x][y]) == 1) {

                        live++;
                    }
                }

                // Live cell becomes dead
                if (board[i][j] == 1 &&
                    (live < 2 || live > 3)) {

                    board[i][j] = -1;
                }

                // Dead cell becomes live
                if (board[i][j] == 0 && live == 3) {
                    board[i][j] = 2;
                }
            }
        }

        // Convert temporary values to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
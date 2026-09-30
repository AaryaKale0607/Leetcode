class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
           int shift = 0;

        // Find the common leftmost bits
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }

        // Restore the common bits
        return left << shift;
    }
};
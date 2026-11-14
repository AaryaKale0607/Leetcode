class Solution {
public:
    bool isUgly(int n) {
            if (n <= 0) {
            return false;
        }

        // Remove all factors of 2
        while (n % 2 == 0) {
            n /= 2;
        }

        // Remove all factors of 3
        while (n % 3 == 0) {
            n /= 3;
        }

        // Remove all factors of 5
        while (n % 5 == 0) {
            n /= 5;
        }

        // If only 1 remains, it is an ugly number
        return n == 1;
    }
};
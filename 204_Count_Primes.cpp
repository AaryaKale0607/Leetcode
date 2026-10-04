#include <vector>

using namespace std ;

class Solution {
public:
    int countPrimes(int n) {
       if (n <= 2)
            return 0;

        // Count 2 separately
        int count = 1;

        // Only store odd numbers
        vector<bool> isPrime(n, true);

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count odd primes
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i])
                count++;
        }

        return count;  
    }
};
class Solution {
public:
    // Helper function to find all primes up to n using the Sieve of Eratosthenes
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect all primes up to n
        vector<int> primes;
        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        // Step 1: Get all primes up to 'right'
        vector<int> primes = sieve(right);
        
        // Step 2: Filter primes in the range [left, right]
        vector<int> validPrimes;
        for (int prime : primes) {
            if (prime >= left) {
                validPrimes.push_back(prime);
            }
        }

        // Step 3: If fewer than two primes, return [-1, -1]
        if (validPrimes.size() < 2) {
            return {-1, -1};
        }

        // Step 4: Find the pair of primes with the smallest difference
        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = 0; i < validPrimes.size() - 1; ++i) {
            int diff = validPrimes[i + 1] - validPrimes[i];
            if (diff < minDiff) {
                minDiff = diff;
                result = {validPrimes[i], validPrimes[i + 1]};
            }
        }

        return result;
    }
};

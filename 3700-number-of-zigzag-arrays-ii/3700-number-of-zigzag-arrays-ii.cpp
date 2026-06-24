
class Solution {
public:
    static const long long MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    vector<long long> multiplyVector(Matrix &A, vector<long long> &v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;       // number of possible values
        int size = 2 * m;        // up states + down states

        if (n == 1) return m;
        if (n == 2) return 1LL * m * (m - 1) % MOD;

        /*
            up[x]   = arrays ending at value x with last move UP
            down[x] = arrays ending at value x with last move DOWN

            Index:
            0 to m - 1       -> up
            m to 2m - 1      -> down
        */

        vector<long long> dp(size, 0);

        // Base case for length 2
        for (int x = 0; x < m; x++) {
            dp[x] = x;             // previous value smaller than x
            dp[m + x] = m - x - 1; // previous value greater than x
        }

        Matrix trans(size, vector<long long>(size, 0));

        /*
            To make new UP:
            previous move must be DOWN
            previous value must be smaller

            newUp[x] = sum of down[y], where y < x
        */
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++) {
                trans[x][m + y] = 1;
            }
        }

        /*
            To make new DOWN:
            previous move must be UP
            previous value must be greater

            newDown[x] = sum of up[y], where y > x
        */
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                trans[m + x][y] = 1;
            }
        }

        // We already have answer for length 2
        // Need to apply transition n - 2 times
        long long power = n - 2;

        while (power > 0) {
            if (power & 1) {
                dp = multiplyVector(trans, dp);
            }

            trans = multiply(trans, trans);
            power >>= 1;
        }

        long long ans = 0;
        for (long long val : dp) {
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};
typedef long long ll;
class Solution {
public:
    int countPermutations(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());

        // First element must be the minimum
        if (nums[0] != mini) return 0;

        int cnt = 0;
        for (auto it : nums) {
            if (it == mini) cnt++;
            if (cnt > 1) return 0; // If minimum appears more than once
        }

        ll ans = 1;
        for (int i = 1; i < n; i++) {
            ans = (ans * i) % MOD; // (n - 1) factorial
        }

        return (int)ans;
    }
};
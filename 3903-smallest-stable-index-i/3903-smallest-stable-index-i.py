class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        # suffix_min[i] = minimum value from i to n - 1
        suffix_min = [0] * n
        suffix_min[n - 1] = nums[n - 1]

        # Build suffix minimum array
        for i in range(n - 2, -1, -1):
            suffix_min[i] = min(nums[i], suffix_min[i + 1])

        # Track maximum from left side
        prefix_max = nums[0]

        for i in range(n):
            # Update prefix maximum
            prefix_max = max(prefix_max, nums[i])

            # Check instability score
            score = prefix_max - suffix_min[i]

            if score <= k:
                return i

        return -1
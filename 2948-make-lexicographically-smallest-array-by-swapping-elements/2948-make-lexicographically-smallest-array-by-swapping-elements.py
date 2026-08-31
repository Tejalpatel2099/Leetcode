class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)

        pairs = sorted((nums[i], i) for i in range(n))
        ans = nums[:]

        start = 0

        while start < n:
            end = start

            # Find all values that belong to the same swappable group
            while end + 1 < n and pairs[end + 1][0] - pairs[end][0] <= limit:
                end += 1

            # Values are already sorted because pairs is sorted
            values = [pairs[i][0] for i in range(start, end + 1)]

            # Sort original indices of this group
            indices = sorted(pairs[i][1] for i in range(start, end + 1))

            # Put smallest values at smallest indices
            for index, value in zip(indices, values):
                ans[index] = value

            start = end + 1

        return ans
        
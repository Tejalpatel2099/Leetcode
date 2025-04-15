//
// “Sure. We're given an unsorted array of integers, and we need to find the
// length of the longest consecutive elements sequence. The elements in the
// sequence must be contiguous in value, but not necessarily in array index.”

// “Also, the problem specifies that the solution must run in O(n) time, so I
// know I can’t sort the array.”

// ✅ 2. Brute-Force Approach First (for context)
// “Initially, I thought of using a brute-force approach where, for each number
// in the array, I check whether num + 1, num + 2, etc., exist — and count the
// length of the sequence.”

// “But this would require linear search for each element inside a loop, leading
// to O(n²) time complexity, which isn't efficient for large arrays.”

// ✅ 3. Transition to Optimized Idea (hashing + O(n))
// “To optimize this, I use an unordered set to store all elements, so I can
// check if a number exists in constant time.”

// “Now, instead of checking every number blindly, I’ll only start counting if
// num - 1 is not in the set. That means num is the start of a potential
// sequence. Then I keep incrementing num + 1, num + 2, and so on, while they
// exist in the set, and count the sequence length.”

// “This way, I ensure each sequence is only counted once, and every number is
// processed at most once — giving us O(n) time.”

// ✅ 4. Time & Space Complexity
// Time Complexity: O(n) — each number is added and processed once.

// Space Complexity: O(n) — for the hash set.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only start if it's the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int count = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

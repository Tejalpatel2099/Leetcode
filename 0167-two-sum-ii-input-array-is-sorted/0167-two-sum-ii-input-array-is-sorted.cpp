// Questions :- 
//1 . What if the array wasn't sorted? --> Leads to using a Hash Map approach (O(n) time, O(n) space).
//2 . Can there be duplicate values in the input?
// 3. Should I return indices or the actual values?

// we are given sorted array and target , so i have to find two distinct numbers
// that add up the target.
// ......Brute forcea pproach...................
// i will be using 2 nested loops and for each number i , i will check every
// number j > i to see if numbers[i] + number[j] == target where TC  :- O(n2)
// checking every possible pairs and SC :- O(1) no extra space used.

// ....................optimized TWO POINTER ...................................
// Since the array is already sorted, I used the two-pointer technique to find the two numbers.
// One pointer starts from the left and the other from the right.
// I keep moving them closer based on whether their sum is smaller or larger than the target.
// This way, I find the answer in a single pass and without using extra space.
// sice array is sorted, i can use two pointer one at begin left = 0; and right
// = n - 1; then i will check sum = numbers[left] + numbers[right] and if sum ==
// target retrun indices , and if sum < target  i will move left forward and if
// sum > target then i will move right backward , this works becuase array is
// sorted  
// Tc :- O(n) single pass with two pointers 
// sc :- O(1) 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
                return {left + 1, right + 1}; // return 1-based index
            else if (sum < target)
                left++; // increase the smaller number
            else
                right--; // decrease the larger number
        }
        return {};
    }
};
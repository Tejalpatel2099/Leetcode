class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - 1;

        // Shrink the window until its size is k
        while (right - left + 1 > k) {
            if (abs(arr[left] - x) > abs(arr[right] - x)) {
                left++;  // remove leftmost element
            } else {
                right--; // remove rightmost element
            }
        }

        // The window [left, right] now contains the k closest elements
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

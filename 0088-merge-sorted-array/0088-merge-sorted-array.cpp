class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int index = m + n - 1;


// loop Merging from the End If the current element in nums1 (nums1[i]) is greater than or equal to the current element in nums2 (nums2[j]), place nums1[i] at position index in nums1.
// Otherwise, place nums2[j] at position index in nums1.

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[index] = nums1[i];
                i--;
            } else {
                nums1[index] = nums2[j];
                j--;
            }
            index--;
        }
        //Copy Remaining Elements from nums2
        
        while (j >= 0) {
            nums1[index] = nums2[j];
            j--;
            index--;
        }
    }
};
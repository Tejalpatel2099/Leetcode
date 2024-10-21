class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // two pointer approach
        //         int i = m - 1;
        //         int j = n - 1;
        //         int index = m + n - 1;

        // // loop Merging from the End If the current element in nums1
        // (nums1[i]) is greater than or equal to the current element in nums2
        // (nums2[j]), place nums1[i] at position index in nums1.
        // // Otherwise, place nums2[j] at position index in nums1.

        //         while (i >= 0 && j >= 0) {
        //             if (nums1[i] >= nums2[j]) {
        //                 nums1[index] = nums1[i];
        //                 i--;
        //             } else {
        //                 nums1[index] = nums2[j];
        //                 j--;
        //             }
        //             index--;
        //         }
        //         //Copy Remaining Elements from nums2

        //         while (j >= 0) {
        //             nums1[index] = nums2[j];
        //             j--;
        //             index--;
        //         }
        //     }
        // };

        // brute force approach

        vector<int> arr3(m + n);

        // Step 2: Copy elements from nums1 into arr3
        for (int i = 0; i < m; i++) {
            arr3[i] = nums1[i];
        }

        // Step 2: Copy elements from nums2 into arr3 using j
        for (int j = 0; j < n; j++) {
            arr3[m + j] = nums2[j];
        }

        // Step 3: Sort the new array
        std::sort(arr3.begin(), arr3.end());

        // Step 4: Copy the sorted elements back to nums1
        for (int i = 0; i < m + n; i++) {
            nums1[i] = arr3[i];
        }
    }
};
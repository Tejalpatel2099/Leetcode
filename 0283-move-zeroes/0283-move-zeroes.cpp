class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // step 1:- we copy all non zero elements to temp array from array given 
        // step 2: - fill all remaining places with zeros in temp array 
        // step 3:- copy all elements  from temp to array 

        int  n = nums.size();
        vector<int>temp(n);

         // take j to keep track on temp array 
         int j = 0; 

         for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                temp[j++] = nums[i];
            }
         }
         while (j < n) {
           temp[j++] = 0; 
         }
            // copying all elements from temp to array 
        for (int i = 0; i < n; i++) {
            nums[i] = temp[i];
        }
     }
};
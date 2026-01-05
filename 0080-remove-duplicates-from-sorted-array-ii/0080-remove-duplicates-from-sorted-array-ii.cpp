class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 2;
        if (n <= 2) return n;
        

        for (int i = 2; i < n; i++) {
            cout<<"print"<<n;
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
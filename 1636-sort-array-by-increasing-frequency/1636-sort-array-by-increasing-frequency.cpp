class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        // Step 1: Count the frequency of each number using an unordered_map
        for(auto it:nums)
        {
            mp[it]++;
        }
        // Step 2: Store the frequency counts in a vector of pairs
        vector<pair<int,int>>arr;
        for(auto&[first,second]:mp)
        {
            arr.push_back({first,second});
        }

        // Step 3: Sort the vector of pairs based on frequency, and by value if frequencies are equal
        sort(arr.begin(),arr.end(),[](const pair<int,int>&a ,const pair<int,int>&b){
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second<b.second;
        });
        
        // Step 4: Construct the result vector based on the sorted frequency data ans to store 

        vector<int>ans;
        
        for(auto &[first,second]:arr)
        {
            while(second > 0)
            {
                ans.push_back(first);
                second--;
            }
        }
        return ans;
    }
};
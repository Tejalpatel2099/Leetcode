#define all(v) (v).begin(),(v).end()
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>>v(100);

        for(auto i:nums){
            int o=i,sm=0;
            while(o){
                sm+=o%10,
                o/=10;
            }

            v[sm].push_back(i);
        }

        int ans=-1;
        for(auto i:v){
            sort(all(i));

            if(i.size()>1)
                ans=max(ans,i.back()+i[i.size()-2]);
        }

        return ans;
    }
};
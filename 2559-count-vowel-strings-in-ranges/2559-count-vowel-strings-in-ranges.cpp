class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const unsigned v=1+(1<<('e'-'a'))+(1<<('i'-'a'))+(1<<('o'-'a'))+(1<<('u'-'a'));
        const int n=words.size(),s=queries.size();
        vector<int> cou(n+1,0);
        for(int i=0;i<n;i++){
            string& w=words[i];
            cou[i+1]=cou[i]+(((1<<(w[0]-'a'))& v) && ((1<<(w.back()-'a')))& v);
        }
        vector<int>ans(s,0);
        int i=0;
        for(auto& q:queries){
            ans[i++]=cou[q[1]+1]-cou[q[0]];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> ans(n, 0);

        stack<int> st;

        int prevTime = 0;

        for (string log : logs) {

            stringstream ss(log);

            string idStr, type, timeStr;

            getline(ss, idStr, ':');
            getline(ss, type, ':');
            getline(ss, timeStr, ':');

            int id = stoi(idStr);
            int time = stoi(timeStr);

            if (type == "start") {

                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }

                st.push(id);

                prevTime = time;

            } else {

                ans[st.top()] += time - prevTime + 1;

                st.pop();

                prevTime = time + 1;
            }
        }

        return ans;
    }
};
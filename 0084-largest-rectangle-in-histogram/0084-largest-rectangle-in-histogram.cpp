class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        int i = 0;

        while (i < n) {
            if (st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i);
                i++;
            } else {
                int top = st.top();
                st.pop();
                int right = i - 1;
                int left = st.empty() ? -1 : st.top();
                int area = heights[top] * (right - left);
                maxArea = max(maxArea, area);
            }
        }

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            int area = heights[top] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int ans = 0;
        stack<int> st;
        for (int i = 0;i<size;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = i;
                if(!st.empty()) {
                    width = i - st.top() - 1;
                }
                ans = max(ans,height*width);
            }
            st.push(i);
        }
        while(!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = size;
            if(!st.empty()) {
                width = size - st.top() - 1;
            }
            ans = max(ans,height*width);
        }
        return ans;
    }
};
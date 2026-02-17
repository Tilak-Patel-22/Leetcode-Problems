class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n=h.size();
        long long ans=0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || h[st.top()]>=h[i])){
                int height=h[st.top()];
                st.pop();
                int right=i;
                int left= st.empty()? -1:st.top();
                long long width=right-left-1;
                ans=max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};

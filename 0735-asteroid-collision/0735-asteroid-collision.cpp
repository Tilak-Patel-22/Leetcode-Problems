class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> st;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] > 0) {
                st.push_back(a[i]);
            }
            else {
                while(!st.empty() && st.back() > 0 && st.back() < -a[i])
                    st.pop_back();
                if(st.empty() || st.back() < 0)
                    st.push_back(a[i]);
                else if(st.back() == -a[i])
                    st.pop_back();
            }
        }
        return st;
    }
};

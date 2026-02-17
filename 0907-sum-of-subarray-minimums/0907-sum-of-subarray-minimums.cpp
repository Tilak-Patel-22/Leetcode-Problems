class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const long long MOD = 1e9+7;

        vector<long long> pse(n), nse(n);
        stack<long long> st;

        for(long long i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(long long i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(long long i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return ans;
    }
};

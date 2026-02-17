class Solution {
public:
stack<int> st;
vector<int> ans;
int n;
vector<int> nse(vector<int>& nums){
    while(!st.empty()) st.pop();
    ans.assign(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i])
            st.pop();

        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> pse(vector<int>& nums){
    while(!st.empty()) st.pop();
    ans.assign(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i])
            st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> gse(vector<int>& nums){
    while(!st.empty()) st.pop();
    ans.assign(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i])
            st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> pge(vector<int>& nums){
    while(!st.empty()) st.pop();
    ans.assign(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i])
            st.pop();
        if(!st.empty()) ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
long long sumMIN(vector<int>& nums){
    vector<int> nse1=nse(nums);
    vector<int> pse1=pse(nums);
    long long sum=0;
    for(int i=0;i<n;i++){
        long long lt=i-pse1[i];
        long long rt=nse1[i]-i;
        long long freq=lt*rt*1LL;
        long long val=freq*nums[i]*1LL;
        sum+=val;
    }
    return sum;
}
long long sumMax(vector<int>& nums){
    vector<int> nge=gse(nums);
    vector<int> p=pge(nums);
    long long sum=0;
    for(int i=0;i<n;i++){
        long long lt=i-p[i];
        long long rt=nge[i]-i;
        long long freq=lt*rt*1LL;
        long long val=freq*nums[i]*1LL;
        sum+=val;
    }
    return sum;
}
long long subArrayRanges(vector<int>& nums) {
    n=nums.size();
    return sumMax(nums)-sumMIN(nums);
}
};

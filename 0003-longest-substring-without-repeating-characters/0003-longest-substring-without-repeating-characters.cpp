class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0; i<256; i++){
            hash[i] = -1;
        }
        int n = s.size();
        int ans = 0;
        int r = 0;
        int l = 0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }int len = r-l+1;
            ans = max(ans, len);
            hash[s[r]] = r;
            r++;
        } return ans;
    }
};
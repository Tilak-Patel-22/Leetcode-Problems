class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        if(n!=t.length())
            return false;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j] && t[i] != t[j])
                    return false;

                if(s[i] != s[j] && t[i] == t[j])
                    return false;
            }
        }
        return true;
    }
};

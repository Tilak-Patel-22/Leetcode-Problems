class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string temp = "";
        for(int i = 0; i<n; i++){
            if(isalnum(s[i])){
                temp+=tolower(s[i]);
            }
        }
        string rev = temp;
        reverse(rev.begin(), rev.end());
        if(temp==rev){
            return true;
        }
        return false;
    }
};
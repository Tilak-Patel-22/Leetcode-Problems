class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> occurance(26,0);
        for(int i = 0; i<s.size(); i++){
            occurance[s[i] -'a']++;
        }
        for(int i = 0; i<s.size(); i++){
            if(occurance[s[i] - 'a'] == 1)
            return i;
        }
        return -1;
    }
};
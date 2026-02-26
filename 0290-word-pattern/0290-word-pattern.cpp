class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp;
        stringstream ss(s);
        while (ss >> temp) {
            words.push_back(temp);
        }
        if (pattern.length() != words.size()) return false;
        for (int i = 0; i < pattern.length(); i++) {
            for (int j = i + 1; j < pattern.length(); j++) {
                if (pattern[i] == pattern[j] && words[i] != words[j]) return false;
                if (pattern[i] != pattern[j] && words[i] == words[j]) return false;
            }
        }
        return true;
    }
};
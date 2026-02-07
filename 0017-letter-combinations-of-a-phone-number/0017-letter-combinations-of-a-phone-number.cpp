class Solution {
public:
void helper(string digits, string output, vector<string>& ans, int idx, string mapping[]){
    if(idx>=digits.length()){
        ans.push_back(output);
        return;
    }
    int num = digits[idx]-'0';
    string value = mapping[num];
    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        helper(digits, output, ans, idx+1, mapping);
        output.pop_back(); 
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int idx = 0; 
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helper(digits, output, ans, idx, mapping);
        return ans;
    }
};
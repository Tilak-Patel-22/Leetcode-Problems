class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()){
            return 0;
        }
        int i = 0; 
        int sign = 1;
        long long num = 0;
        while(i<s.length() && s[i] == ' '){
            i++;
        }
        if(s.length() && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }
        while(i<s.length() && s[i] >= '0' && s[i] <= '9'){
            int digit = s[i] - '0';
            num = num*10+digit;
            if(sign == 1 && num>INT_MAX) return INT_MAX;
            if(sign == -1 && -num<INT_MIN) return INT_MIN;
            i++;
        }
        return sign*num;
    }
};
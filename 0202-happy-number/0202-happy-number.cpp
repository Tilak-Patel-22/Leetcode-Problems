class Solution {
public:
int getsum(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum += digit*digit;
        n/=10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.count(n)){
                return false;
            }
            s.insert(n);
            n = getsum(n);
        }
        return true;
    }
};
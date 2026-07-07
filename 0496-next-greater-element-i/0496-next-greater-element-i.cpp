/** 
Sabse pehle hum nums2 ke har element ka Next Greater Element nikalenge kyunki final answer nums1 ke elements ke liye chahiye aur nums1 ke saare elements nums2 me present hain.
Next Greater Element nikalne ke liye hum stack use karege aur nums2 ko right se left traverse karege kyunki hume har element ke right side me greater element find karna hai.
Har current element ke liye  stack ke top se saare chhote ya equal elements pop kar dege kyunki wo current element ka next greater nahi ban sakte.
Pop karne ke baad agar stack empty ho gaya iska matlab right side me koi greater element nahi hai toh nge[i] = -1 store karenge.
Agar stack empty nahi hai toh stack ka top current element se bada hoga isliye nge[i] = st.top() store karenge.
Uske baad current element ko stack me push karege kyuki ye aage kisi left-side element ka Next Greater Element ban sakta hai.
Is process ke baad hamare paas nums2 ke har element ka NGE array ready ho jayega. Example:
nums2 = [1,3,4,2] → nge = [3,4,-1,-1]
Ab nums1 ke har element ko nums2 me search karege. Jis index j par element milega usi index ka nge[j] final ans me push kar denge.
Finally ans vector return kar denge.

**/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i])
                st.pop();
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};

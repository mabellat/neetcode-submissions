class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool b_set = false;
        for(int i = 0;i<n;i++){
            if(s[i] == 'b'){
                if(b_set) continue;
                else b_set = true;
            }
            else{
                if(b_set) return false;
            }
        }
        return true;
    }
};
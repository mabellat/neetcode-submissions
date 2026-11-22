class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, j = n-1, ans = 0;
        while(i<=j){
            if(i==j){
                ans++;
                break;
            }
            int sum = people[i]+people[j];
            if(sum > limit){
                ans++;
                j--;
            }else{
                // we can make them sit in 1 boat
                ans++;
                j--;
                i++;
            }
        }
        return ans;
    }
};
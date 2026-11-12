class Solution {
public:
    bool solve(vector<int>& piles, int h, int mid){
        int x = 0;
        for(auto it:piles){
            x = x + ceil((double)it/mid);
        }
        return x<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(begin(piles), end(piles));

        while(l<r){
            int mid = l+(r-l)/2;
            if(solve(piles, h, mid)){
                r = mid;
            }else l = mid+1;
        }
        return r;
    }
};
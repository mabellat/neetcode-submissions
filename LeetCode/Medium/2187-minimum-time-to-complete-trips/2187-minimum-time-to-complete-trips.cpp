class Solution {
public:
    bool solve(vector<int>& time, int totalTrips, long long mid){
        long long x = 0;
        for(auto it:time){
            x+=mid/it;
        }
        return x>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l = 0, h = 1LL* *min_element(begin(time), end(time)) * totalTrips;
        while(l<h){
            long long mid = l+(h-l)/2;

            // let's say it is 6
            // so we need to calculate if it is possible for the total_trips to be 5, 
            // for that given n
            if(solve(time, totalTrips, mid)){
                h = mid;
            }else l = mid+1;
        }
        return h;
    }
};
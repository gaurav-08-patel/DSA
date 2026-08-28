class Solution {
public:
    int countDays(vector<int> weights, int capacity){
        int dayCount=1, load = 0;

        for(int i=0; i<weights.size(); i++){
            if(load + weights[i] > capacity ){
                dayCount++;
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }

        return dayCount;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        //using binary search on answer to find
        int sum=0, mx = INT_MIN;
        //finding summation of weights
        for(int w : weights){
            sum += w;
            mx = max(mx,w);
        }
        //to find least capacity it will range between max-weight of item to summation of all weights 
        int low = mx, high = sum;

        while(low <= high){
            int mid = (low + high)/2;

            if(countDays(weights,mid) <= days){
                high = mid - 1;
            }else low = mid + 1;
        }

        return low;
    }
};
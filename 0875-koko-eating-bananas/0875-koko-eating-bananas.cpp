class Solution {
public:
    int findMax(vector<int> nums){
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size() ; i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }

    //returns total hour needed to eat bananas at rate h
    // using long long data type because it might overflow or return wrong value
    long long getTotalHours(vector<int> nums , int perHour){
        long long total = 0;

        for(int i =0; i<nums.size(); i++){
            // cast to double to get in point then ceil that value
            total += ceil( (double)nums[i] / (double)perHour );
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //using binary seacrch on answers
        // AND answers lies between 1 to maxNumber in piles
        int maxVal = findMax(piles);
        int low =1, high = maxVal;
        int ans=maxVal;

        while(low <= high){
            int mid = (low + high)/2;
            long long totalHours = getTotalHours(piles,mid);

            if(totalHours <= h) {
                // this means koko is eating more banana in less time , so decrease hourly banana
                ans = mid;
                high = mid - 1; 
            }else{
                low = mid + 1;
            }

        }

        return ans;   
    }
};
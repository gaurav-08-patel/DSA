class Solution {
public:
    pair<int,int> findMinMax(vector<int> nums){
        int mini=INT_MAX, maxi=INT_MIN;
        for(int n : nums){
            mini = min(mini,n);
            maxi = max(maxi,n);
        }

        return {mini,maxi};
    }

    bool findIsPossible(vector<int> bloomDay , int reqBouquets , int k , int currDay){
        int bouquetsCount = 0 , count = 0;

        for(int d : bloomDay){
            if(currDay >= d){// flower is bloomed
                count++;
            }else{// not bloomed 
                bouquetsCount += (count/k);
                count=0;
            }
        }
        bouquetsCount += (count/k);

        return bouquetsCount >= reqBouquets; 
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        //this means there are not enough flower
        if(bloomDay.size() < m * 1LL * k * 1LL) return -1; // long long to prevent overflow

        // using binary search on answers to find minimum no. of days to make m bouquets
        pair<int,int> minmax = findMinMax(bloomDay);
        int low = minmax.first, high = minmax.second;
        int ans=minmax.second;

        while(low <= high){
            int mid = (low + high)/2;

            if(findIsPossible(bloomDay,m,k,mid)) {
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return ans; // can also return low instead of storing in ans because low will always point to min possible days and high will point to wrong answer (ie. day at which required bouquets cannot be made)
    }
};
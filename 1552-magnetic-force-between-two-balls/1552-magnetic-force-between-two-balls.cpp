class Solution {
public:
    bool canWePlaceBall(vector<int> &position , int m , int force){
        int ballsCount=1, lastB = position[0];

        for(int i=0; i<position.size(); i++){
            if(position[i] - lastB >= force){
                ballsCount++;
                lastB=position[i];
            }

            if(ballsCount >= m) return true;
        }   
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        //using binary search on answers
        sort(position.begin(), position.end());//sorting bcz adjacent position will have min-force 

        int low=1, high = position[n-1] - position[0];
        int ans=-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(canWePlaceBall(position , m , mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        
        return ans;  //or return high (at first low will pointing to possible polarity and high to not-possible then after BS both will change there polarity then  high will be pointing to answer)
        //to understand just run dry run
    }
};
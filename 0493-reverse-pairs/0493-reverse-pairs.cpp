class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int i = low, j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= high) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }
        for (int k = 0; k < temp.size(); k++) {
            nums[low + k] = temp[k];
        }
    }

    int countPairs(vector<int>& nums , int low , int mid , int high ){
        int count=0;
       int right = mid + 1;

        for(int i = low; i<=mid; i++){
            while(right <= high && (long long)nums[i] > (long long)nums[right] * 2L) right++; // type casted tp long long to prevent overflow of integer
            count += (right - (mid + 1));
        }
        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums,low,mid,high);
        merge(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
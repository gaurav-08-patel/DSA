class Solution {
public:
    int nextGreaterElement(int n) {

        //following next permutation approach
        string s = to_string(n);

        int i = s.size() - 2;

        //finding first decreasing number from last
        while(i >= 0 && s[i] >= s[i+1]){
            i--;
        }

        //no next permutation
        if(i < 0) return -1;

        int j = s.size() - 1; 
        //find just greater number than s[i] from last 
        while(s[j] <= s[i]){
            j--;
        }

        //now swap numbers
        swap(s[i],s[j]);

        // reverse suffix after idx i + 1 
        reverse(s.begin() + i + 1 , s.end());

        //now again convert to integer
        
        //stoll means string to long long 
        long long ans = stoll(s); //converting to long long first because re-arranged number might exceed safe_limit of 32-bit signed integer ( INT_MAX )  

        //safe check before returning 
        return ans > INT_MAX ? -1 : (int)ans; // cast to int before returning 

    }
};
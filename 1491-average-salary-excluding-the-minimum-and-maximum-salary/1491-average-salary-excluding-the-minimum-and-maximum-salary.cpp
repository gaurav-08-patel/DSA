class Solution {
public:
    double average(vector<int>& salary) {
        int min=salary[0],max=0;
        double sum=0.0;

        for(int s : salary){
            if(max < s) max = s;
            if(min > s ) min =s;
            sum+=s;
        }

        return (sum - min - max)/(salary.size()-2);


    }
};
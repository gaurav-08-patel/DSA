class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        //BS approach , first find insert position then check if it overlaps or not 

        // Searching for insert position
        int left = 0 , right = bookings.size();
        while(left < right){
            int mid = (left + right) / 2;

            if(bookings[mid].first < startTime) left = mid + 1; // look right
            else right = mid; // look left
        }     

        //check on left and right of insert position if it overlaps or not
        if(left > 0 && bookings[left - 1].second > startTime) return false;
        if(left < bookings.size() && bookings[left].first < endTime) return false;

        //insert if everything is OK 
        bookings.insert(bookings.begin() + left , {startTime , endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
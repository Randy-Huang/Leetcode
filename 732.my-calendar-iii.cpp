/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
private:
    map<int, int> books;

public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        books[startTime]++;
        books[endTime]--;
        //printf("enter start: %d, end: %d\n",startTime, endTime);

        int boundaryCount = 0;
        int k = 0;
        for (auto &event : books) {
            boundaryCount += event.second;
            k = max(k, boundaryCount);
        }

        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end


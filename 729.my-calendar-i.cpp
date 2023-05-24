/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start

// Reference: https://www.cnblogs.com/grandyang/p/7920253.html

// Solution 2: Use binary search with map
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // return iterator which contains elements >= start (key) with ascending order
        auto overlays = schedules.lower_bound(start); 

        // exist an overlay in the first half part of event
        // for example: new = [10, 20], exist an interval [15, 25] that 
        // interval->first (15) < end value of new input (20)
        // |---------| new input
        //      |----------| one interval in overlays iterator
        if (overlays != schedules.end() && overlays->first < end) {
            return false;
        }

        // exist an overlay in the second half part of event 
        // we can use the previous interval and compare its end value with input's start value
        // we just make sure the legal interval of new input's smaller than the previous internal's end value
        //      |----------| new input
        // |----------| one interval in overlays iterator
        if (overlays != schedules.begin() && prev(overlays)->second > start ) {
            return false;
        }

        schedules[start] = end;
        return true;
    }
private:
    map<int, int> schedules;
};

// Solution 1: brute force with TC: O(N^2)
// class MyCalendar {
// public:
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         for (auto event : schedules) {
//             // exist an overlay in the first half part of event
//             if (start >= event.first && start < event.second) {
//                 return false;
//             }

//             // exist an overlay in the second half part of event
//             if (start <= event.first && end > event.first) {
//                 return false;
//             }
//         }

//         schedules.push_back({start, end});
//         return true;
//     }

// private:
//     vector<pair<int, int>> schedules;
// };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


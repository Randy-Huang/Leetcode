/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start
// Solution 2: Boundary count
class MyCalendarTwo {
private:
    map<int, int> books;

public:
    MyCalendarTwo() {
    
    }

    bool book(int start, int end) {
        books[start]++;
        books[end]--;

        int counts = 0;
        for (auto &event : books) {
            counts += event.second;
            if (counts == 3) {
                books[start]--;
                books[end]++;
                return false;
            }

            if (event.first > end) {
                break;
            }
        }

        return true;
    }
};

// Solution 1: Brute Force
// class MyCalendarTwo {
// private:
//     set<pair<int, int>> intervals;
//     set<pair<int, int>> overlays;

// public:
//     MyCalendarTwo() {
        
//     }
    
//     bool book(int start, int end) {
//         for (auto &overlay : overlays) {
//             if (start >= overlay.second || overlay.first >= end) {
//                 continue;
//             }

//             return false;
//         }

//         for (auto &interval : intervals) {
//             if (start >= interval.second || interval.first >= end) {
//                 continue;
//             }

//             overlays.insert({ max(start, interval.first), min(end, interval.second) });
//         }

//         intervals.insert({ start, end });

//         return true;
//     }
// };

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end


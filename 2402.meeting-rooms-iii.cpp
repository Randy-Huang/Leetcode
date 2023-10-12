/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * [2402] Meeting Rooms III
 */

// @lc code=start
class Solution 
{
private:
    struct roomNode
    {
        long endTime;
        int roomId;
    };

    struct compareRooms
    {
        bool operator()(const roomNode& a, const roomNode& b)
        {
            // default is "<", which means the heap is max heap
            // here we use min heap and we use greator
            return a.endTime == b.endTime ? 
                    a.roomId > b.roomId :
                    a.endTime > b.endTime;
        }
    };

public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        // 1. which room is occupied or free 
        // 2. If room is ocuupied, what meeting occupy it?
        // 3. which room is the most being used?

        // We don't know all meetings whether they are
        // been sorted, so we must do this
        sort(meetings.begin(), meetings.end());

        // Record all of the induvidual room 
        // their usage count
        vector<int> roomUsedCount(n, 0);

        // sort the current meetings the top is the earilest 
        // finished with the room that is used
        priority_queue<roomNode, 
                       vector<roomNode>,
                       compareRooms> heldMeetings;

        // sort the current roomes and it's top is the 
        // lowest number room
        priority_queue<int, 
                       vector<int>, 
                       greater<int>> availableRoomIds;
        for (int i = 0; i < n; i++) 
        {
            availableRoomIds.push(i);
        }

        for (auto meeting : meetings) 
        {
            long start = meeting[0];
            long end = meeting[1];
            
            // 1. The first thing is to check how many rooms
            // have been finished when we want to schedule
            // a new meeting but its start time is >= their endTime
            // 
            // For example:
            // before we schedule [10,7]
            // we need to end [0,10] and [1,9]
            // so that we can arrange room id 0 for [10,7]
            // [[0,10],[1,9],[10,7],[3,4]]
            while (!heldMeetings.empty() && heldMeetings.top().endTime <= start) 
            {
                roomNode meetingFinish = heldMeetings.top(); heldMeetings.pop();
                availableRoomIds.push(meetingFinish.roomId);
            }

            // All rooms are occupied
            // we can assume the fact that 
            // the current must be delayed because
            // we've checked those scheduled meeting endTime <= start
            // so we just calcuate the diff time and add it to 
            // the next meeting to schedule
            if (heldMeetings.size() == n)
            {
                roomNode meetingFinish = heldMeetings.top(); heldMeetings.pop();
                availableRoomIds.push(meetingFinish.roomId);
                long delayedTime = meetingFinish.endTime - start;
                end += delayedTime;
            }

            int room = availableRoomIds.top(); availableRoomIds.pop();
            roomUsedCount[room]++;

            roomNode scheduleMeeting;
            scheduleMeeting.endTime = end;
            scheduleMeeting.roomId = room;
            heldMeetings.push(scheduleMeeting);
        }

        // int maxUsedRoomId = 0;
        // for (int i = 0; i < n; i++) 
        // {   
        //     //cout << i << ":" << roomUsedCount[i] << ", ";
        //     maxUsedRoomId = roomUsedCount[maxUsedRoomId] < roomUsedCount[i]
        //                     ? i : maxUsedRoomId;
        // }

        return max_element(roomUsedCount.begin(), roomUsedCount.end()) - roomUsedCount.begin() ;
    }
};
// @lc code=end


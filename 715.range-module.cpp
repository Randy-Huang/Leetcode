/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
class RangeModule 
{
private: 
    map<int, int> rangeMap; /* [left, right) */

    pair<int, int> findRange(int left, int right)
    {
        // 1. find the first value that is less than or equal to "left"
        // when it exist and use --it
        std::map<int, int>::iterator leftIterator = rangeMap.upper_bound(left);

        // 2. find the first value that is less than or equal to "right"
        // when it exist and use --it
        std::map<int, int>::iterator rightIterator = rangeMap.upper_bound(right);

        // 3. the first thing is to find the second value of leftIterator
        // does overlap with left
        if (leftIterator != rangeMap.begin()) 
        {
            // try to find the value which less than or equal to "left"
            // if the value exist, we want to find its second value 
            // to see if it is overlap with left
            --leftIterator; 

            // no overlap, which means [first, second] when we're doing
            // --leftIterator don't reach the left
            // for example [left, right) = [21, 24]
            // and leftIterator assumed [10, 19]
            // we can see 19 in the leftIterator is less than 21 of left
            // so we need to resume the leftIterator that is greater than left
            if (leftIterator->second < left) 
            {
                ++leftIterator;
            }
        }

        // if leftIterator is the same as rightIterator
        // it means there is no any elemetns 
        // in the range covere with [left, right)
        if (leftIterator == rightIterator) 
        {
            return {left, right};
        }

        // 4. leftIterator is less than rightIterator and 
        // some part of range in leftIterator covered with or be involved in [left, right)
        int start = min(left, leftIterator->first);

        // 5. Now we want to find the right between the given right or in rightIterator
        // all elements in rightIterator are greater than right
        // we have to --rightIterator to find the which value are greater than another
        --rightIterator;
        int end = max(right, rightIterator->second);
        
        // 6. finally, we can erase all key between leftIterator and rightIterator
        // that is overlapped. For example, we have a map contains below:
        // 1 -> 10
        // 3 -> 30
        // 5 -> 50
        // 7 -> 70
        // and we want to find the range [2, 6]
        // if we execute rangeMap.erase(leftIterator, rightIterator)
        // rangeMap will become 2 data:
        // 1 -> 10
        // 7 -> 70
        ++rightIterator;
        rangeMap.erase(leftIterator, rightIterator);

        return {start, end};
    }

public:
    // The first thing we can use tree map to store the start point of every range 
    // the key is as left and the value is as right
    // tree map also sort the left key ordered 
    // when we want to query a range does contains in an existed range
    // we can use binary search to speed up the time complexity  

    RangeModule() 
    {
        
    }
    
    void addRange(int left, int right) 
    {
        pair<int, int> range = findRange(left, right);
        rangeMap[range.first] = range.second;  
    }
    
    bool queryRange(int left, int right) 
    {
        std::map<int, int>::iterator it = rangeMap.upper_bound(left);
        if (it != rangeMap.begin()) 
        {   
            // means it.first <= left 
            // and we can promise the existted range contains left
            --it; 

            return right <= it->second;
        }

        return false;
    }
    
    void removeRange(int left, int right) 
    {
        pair<int, int> range = findRange(left, right);
        if (range.first != left)
        {
            rangeMap[range.first] = left; // [range.first, left)
        } 

        if (range.second != right) 
        {
            rangeMap[right] = range.second;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end


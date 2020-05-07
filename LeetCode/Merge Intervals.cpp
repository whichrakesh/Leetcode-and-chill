// https://leetcode.com/problems/merge-intervals/

class Solution {
    static bool compareInterval(vector<int> i1, vector<int> i2) 
    { 
        return (i1[0] < i2[0]); 
    } 
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end(), compareInterval);
        if(intervals.size() > 0){
            mergedIntervals.push_back(intervals[0]);
            for(int i = 1; i < intervals.size(); i++){
                if(mergedIntervals[mergedIntervals.size() - 1][1] < intervals[i][0]){
                    mergedIntervals.push_back(intervals[i]);
                }
                else {
                    mergedIntervals[mergedIntervals.size() - 1][1] = max(mergedIntervals[mergedIntervals.size() - 1][1], intervals[i][1]);
                }
            }
        }
        return mergedIntervals;
    }
};
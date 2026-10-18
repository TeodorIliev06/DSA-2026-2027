class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& first, const vector<int>& second) {
                 return first[1] < second[1];
             });

        int size = intervals.size();
        int keep = 1, end = intervals[0][1];
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] >= end) {
                keep++;
                end = intervals[i][1];
            }
        }

        return size - keep;
    }
};

// https://leetcode.com/problems/insert-interval/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res = intervals;
        int i = 0, overlap = 0, n = res.size();
        while (i < n) {
            if (newInterval.end < res[i].start) break;
            else if (newInterval.start > res[i].end) {}
            else {
                newInterval.start = min(newInterval.start, res[i].start);
                newInterval.end = max(newInterval.end, res[i].end);
                ++overlap;
            }
            ++i;
        }
        if (overlap > 0) {
            res.erase(res.begin() + i - overlap, res.begin() + i);
        }
        res.insert(res.begin() + i - overlap, newInterval);
        return res;
    }
};

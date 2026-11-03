class Solution {
public:
    bool canFinish(const vector<int>& piles, int target, int hours) {
        int hoursNeeded = 0;
        for (auto pile : piles) {
            hoursNeeded += (pile + target - 1) / target;
        }

        return hoursNeeded <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(canFinish(piles, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (x < 2) {
            return x;
        }

        int left = 1, right = x / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long targetSquared = (long)mid * mid;
            if (targetSquared == x) {
                return mid;
            } else if (targetSquared < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }
};

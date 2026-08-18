#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int l = 0;
        int r = 0;

        while (r < nums.size() - 1) {
            count++;

            int replacement = r;

            while (l <= r) {
                replacement = max(replacement, l + nums[l]);
                l++;
            }

            r = replacement;
        }

        return count;
    }
};
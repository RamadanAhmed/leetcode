/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
static int __ = []() {
	std::ios::sync_with_stdio(false);
	return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto end = numbers.size() - 1;
        auto start = 0;
        while (start <= end)
        {
            if (target == numbers[start] + numbers[end]){
                return {start + 1,end + 1};
            }
            else if(target <= numbers[start] + numbers[end]) {
                end--;
            }
            else {
                start++;
            }
        }
        return {};
    }
};


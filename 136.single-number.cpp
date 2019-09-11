/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
    // Second Solution using bit-manipulation
    int singleNumber(vector<int>& nums) noexcept{
        auto result = 0;
        for(auto elem : nums) {
            result ^= elem;
        }
        return result;
    }

    // First Solution using hash-table
    int singleNumberHash(vector<int>& nums) noexcept {
        std::unordered_set<int> num_set;
        for (auto const num : nums) {
            if(num_set.find(num) == num_set.end()){
                num_set.insert(num);
            }
            else {
                num_set.erase(num);
            }
        }
        return *(num_set.begin());       
    }  
};
// static auto x = []() {
// 	// turn off sync
// 	std::ios::sync_with_stdio(false);
// 	// untie in/out streams
// 	cin.tie(NULL);
// 	return 0;
// }();


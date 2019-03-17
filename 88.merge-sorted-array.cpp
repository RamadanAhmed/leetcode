/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (34.96%)
 * Total Accepted:    334.3K
 * Total Submissions: 956.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if(m == 0 && n > 0) {
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            nums1.resize(m + n);
            return;
        }
        if(n == 0) return;
        if(m == 0) return;
        auto iter_num1 = 0;
        auto iter_num2 = 0;
        auto curr_size = m;
        auto m_used = 0;
        while(iter_num2 < n) {
            if(nums1[iter_num1] > nums2[iter_num2]) {
                nums1.insert(nums1.begin() + iter_num1, nums2[iter_num2]);
                ++iter_num2;
                ++iter_num1;
                ++curr_size;
            } else if(m_used >= m) {
                nums1.insert(nums1.begin() + curr_size, nums2.begin() + iter_num2, nums2.end());
                break;
            } else {
                ++iter_num1;
                m_used++;
            }
        }
        nums1.resize(m + n);
    }
};

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	cin.tie(NULL);
	return 0;
}();

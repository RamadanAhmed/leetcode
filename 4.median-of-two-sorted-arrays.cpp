/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (29.21%)
 * Likes:    9894
 * Dislikes: 1512
 * Total Accepted:    927.8K
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 * 
 * Follow up: The overall run time complexity should be O(log (m+n)).
 */
// 1 2 3 |4 5
// 1 2 |3 4
// @lc code=start
#include <limits>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            std::swap(nums1, nums2);

        auto l = 0;
        auto h = nums1.size();
        const auto tsize = nums1.size() + nums2.size();
        const auto n1 = nums1.size();
        const auto n2 = nums2.size();
        while (l <= h)
        {
            const auto mid1 = (l + h) / 2;
            const auto mid2 = (tsize + 1) / 2 - mid1;

            const auto left1 = mid1 > 0 ? nums1[mid1 - 1] : std::numeric_limits<int>::min();
            const auto right1 = mid1 < n1 ? nums1[mid1] : std::numeric_limits<int>::max();
            const auto left2 = mid2 > 0 ? nums2[mid2 - 1] : std::numeric_limits<int>::min();
            const auto right2 = mid2 < n2 ? nums2[mid2] : std::numeric_limits<int>::max();

            if (left1 <= right2 && left2 <= right1)
            {
                if (tsize % 2 == 0)
                {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                }
                else
                {
                    return std::max(left1, left2);
                }
            }
            if (left1 > right2)
            {
                h = mid1 - 1;
            }
            else
            {
                l = mid1 + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

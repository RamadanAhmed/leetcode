/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (35.14%)
 * Likes:    393
 * Dislikes: 114
 * Total Accepted:    280.2K
 * Total Submissions: 796.9K
 * Testcase Example:  '"/home/"'
 *
 * Given a string path, which is an absolute path (starting with a slash '/')
 * to a file or directory in a Unix-style file system, convert it to the
 * simplified canonical path.
 * 
 * In a Unix-style file system, a period '.' refers to the current directory, a
 * double period '..' refers to the directory up a level, and any multiple
 * consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
 * problem, any other format of periods such as '...' are treated as
 * file/directory names.
 * 
 * The canonical path should have the following format:
 * 
 * 
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period '.' or double period
 * '..')
 * 
 * 
 * Return the simplified canonical path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: path = "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: path = "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: path = "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: path = "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 * 
 * 
 */

// @lc code=start
#include <sstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        std::vector<string> paths;
        std::istringstream split(path);
        std::vector<std::string> tokens;
        for (std::string each; std::getline(split, each, '/'); tokens.push_back(each));
        for (auto const &token : tokens)
        {
            if (token == "..")
            {
                if(!paths.empty()){
                    paths.pop_back();
                }
            }
            else if (token == "." || token.empty())
            {
                continue;
            }
            else
            {
                paths.push_back(token);
            }
        }
        if(paths.empty()) {
            return "/";
        }
        else{
            std::string result;
            int i = 0;
            for (i = 0 ; i < paths.size(); ++i){
                result += "/" + paths[i];
            }
            return result;    
        }
        
    }
};
// @lc code=end

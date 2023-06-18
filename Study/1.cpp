#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;        // 创建一个 map，用于存储数字和其索引的映射关系
        vector<int> b(2, -1);   // 创建一个大小为2、初始值为-1的 vector，用于存储结果的下标

        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i]) > 0) {
                // 如果 map 中存在目标值与当前数字之差的映射关系，
                // 则表示找到了两个数的和等于目标值
                b[0] = a[target - nums[i]];   // 设置第一个数的下标
                b[1] = i;                     // 设置第二个数的下标
                break;
            }

            a[nums[i]] = i;  // 将当前数字及其索引添加到 map 中，用于后续查找
        }

        return b;   // 返回存储结果下标的 vector
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    cout << "下标是: " << result[0] << ", " << result[1] << endl;

    return 0;
}

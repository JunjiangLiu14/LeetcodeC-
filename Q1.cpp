#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    // 创建一个哈希表，用来存储已经访问过的元素及其索引
    unordered_map<int, int> num_to_index;
    
    // 遍历数组中的每一个元素
    for (int i = 0; i < nums.size(); ++i) {
        // 计算当前元素与目标值的差值
        int difference = target - nums[i];
        
        // 检查差值是否已经存在于哈希表中
        if (num_to_index.find(difference) != num_to_index.end()) {
            // 如果存在，返回差值的索引和当前元素的索引
            return {num_to_index[difference], i};
        }
        
        // 如果不存在，将当前元素及其索引添加到哈希表中
        num_to_index[nums[i]] = i;
    }
    
    // 如果没有找到符合条件的两个数，返回空向量（或其他适当的处理方式）
    return {};
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "Result for example 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);
    cout << "Result for example 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string buildPostOrder(string &pre, string &in, int pre_start, int pre_end, int in_start, int in_end, unordered_map<char, int> &in_map) {
    if (pre_start > pre_end || in_start > in_end) {
        return "";
    }
    char root_val = pre[pre_start];
    int in_root_pos = in_map[root_val];
    int left_size = in_root_pos - in_start;
    string left_post = buildPostOrder(pre, in, pre_start + 1, pre_start + left_size, in_start, in_root_pos - 1, in_map);
    string right_post = buildPostOrder(pre, in, pre_start + left_size + 1, pre_end, in_root_pos + 1, in_end, in_map);
    return left_post + right_post + root_val;
}

int main() {
    string inorder, preorder;
    cin >> inorder >> preorder;
    int n = inorder.size();
    unordered_map<char, int> in_map;
    for (int i = 0; i < n; ++i) {
        in_map[inorder[i]] = i;
    }
    string postorder = buildPostOrder(preorder, inorder, 0, n - 1, 0, n - 1, in_map);
    cout << postorder << endl;
    return 0;
}
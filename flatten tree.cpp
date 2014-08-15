#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	TreeNode* right;
	TreeNode* left;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        helper_stack.push(root);
        TreeNode* cur = nullptr;
        while (!helper_stack.empty()) {
            cur = helper_stack.top();
 			helper_stack.pop();
						
            if (cur -> right != nullptr) {
                helper_stack.push(cur -> right);
            }
            if (cur -> left != nullptr) {
                helper_stack.push(cur -> left);
            }

			
            cur -> left = nullptr;
            cur -> right = helper_stack.empty() ? nullptr : helper_stack.top();

        }
    }
private:
    stack<TreeNode*> helper_stack;
};

int main(int argc, char *argv[]) {
	TreeNode a(0);
	TreeNode* ptr = &a;
	Solution test;
	test.flatten(ptr);
}
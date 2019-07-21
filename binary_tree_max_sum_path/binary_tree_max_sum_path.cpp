#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    };

class Solution {
public:
    struct Pair {
        int val;
        int best;
    };

    Pair propogate(TreeNode* root) {
        Pair answer;
        if ((root->left == nullptr) and (root->right == nullptr)) {
            answer.val = root->val;
            answer.best = root->val;
        }
        else {
            Pair left;
            Pair right;
            if (root->left == nullptr) {
                right = propogate(root->right);
                answer.val = right.val + root->val;
                cout << answer.val << endl;
                if (answer.val > right.best) {
                    answer.best = answer.val;
                    cout << answer.val << endl;
                }
                else {
                    answer.best = right.best;
                }
            }
            else if (root->right == nullptr) {
                left = propogate(root->left);
                answer.val = left.val + root->val;
                cout << answer.val << endl;
                if (answer.val > left.best) {
                    answer.best = answer.val;
                    cout << answer.val << endl;
                }
                else {
                    answer.best = left.best;
                }
            }
            else {
                left = propogate(root->left);
                right = propogate(root->right);

                if (right.val > left.val) {
                    answer.val = root->val + right.val;
                    cout << answer.val << endl;
                }
                else {
                    answer.val = root->val + left.val;
                    cout << answer.val << endl;
                }

                answer.best = left.val + root->val + right.val;
                cout << answer.best << endl;

                if (answer.best < left.best) {
                    answer.best = left.best;
                    cout << answer.best << endl;
                }

                if (answer.best < right.best) {
                    answer.best = right.best;
                    cout << answer.best << endl;
                }
            }
        }
        if (answer.best < root->val) {
            answer.best = root->val;
            cout << answer.best << endl;
        }
        return answer;
    }

    int maxPathSum(TreeNode* root) {
        Pair answer = propogate(root);
        if (answer.best > answer.val) {
            return answer.best;
        }
        else {
            return answer.val;
        }
    }
};
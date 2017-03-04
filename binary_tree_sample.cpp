#include <iostream>
using namespace std;

struct TreeNode {
    int item;
    TreeNode *left;
    TreeNode *right;
};

int countNodes(TreeNode *root){
    // Count the nodes in the binary tree to which
    // root points, and return the answer.
    if (root == NULL) return 0;
    else {
        int count = 1;
        count += countNodes(root->left);
        count += countNodes(root->right);

        return count;
    }
}
int compare(int parentItem, int item){
    if(parentItem<item) return -1;
    else return 1;
}

void insert(TreeNode* node, int item){
    int compareVal = compare(node->item,item);
    if (compareVal<0){
        if(node->left == NULL){
            node->left = new TreeNode();
            node->left->item = item;
        } else insert(node->left, item);
    }
    else {
        if(node->right == NULL){
            node->right = new TreeNode();
            node->right->item = item;
        } else insert(node->right, item);
    }
}


int main(){
    //struct TreeNode pohon;
    TreeNode *pohon = new TreeNode();
    int data[7] = {4,2,6,1,3,5,7};
    pohon->item = data[0];
    cout << countNodes(pohon) << endl;
    for(int i=1; i<7;i++){
        insert(pohon, data[i]);
    }
    cout << countNodes(pohon) << endl;
    return 0;
}

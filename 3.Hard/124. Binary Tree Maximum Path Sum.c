#include<stdio.h>
#include<math.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int result = 0;

int max(int a,int b){
    return (a > b) ? a : b;
}
int DFS(struct TreeNode* root){
    if(!root) return 0;
    int leftPathSum = max(DFS(root -> left), 0);
    int rightPathSum = max(DFS(root -> right),0);

    result = max(result,root -> val + leftPathSum + rightPathSum);

    return root -> val + max(leftPathSum,rightPathSum);
}

int maxPathSum(struct TreeNode* root){
    if(!root) return 0;
    DFS(root);
    return result;
}

int main(){
    struct TreeNode* root;
    root -> val = 0;
    root -> left = NULL;
    root -> right = NULL;
    printf("%d",maxPathSum(root));
}

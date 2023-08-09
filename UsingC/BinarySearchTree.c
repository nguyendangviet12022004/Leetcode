#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
struct node{
    int val;
    struct node* left;
    struct node* right;
} ;

struct node* newNode(int val){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root -> val = val;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

struct node* insert(struct node* root, int val){
    if(!root) return newNode(val);
    else {
        if(val < root -> val) root -> left = insert(root->left, val);
        else root -> right = insert(root -> right,val);
        return root;
    }
};

void inorderTraveral(struct node* root){
    if(root){
        inorderTraveral(root -> left);
        printf("%d ",root -> val);
        inorderTraveral(root -> right);
    }
}

void preorderTraveral(struct node* root){
    if(root) {
        printf("%d ",root -> val);
        preorderTraveral(root -> left);
        preorderTraveral(root -> right);
    }
}

void postorderTraveral(struct node* root){
    if(root){
        postorderTraveral(root -> left);
        postorderTraveral(root -> right);
        printf("%d ",root -> val);
    }
}

void BFS(struct node*root){
    if(!root) return ;
    struct node** que = (struct node**) malloc(100 * sizeof(struct node*));
    que[0] = root;
    int l = 1;
    int i = 0 ;
    while(i < l){
        struct node* front = que[i];
        if(front -> left) que[l++] = front -> left;
        if(front -> right) que[l++] = front -> right;
        printf("%d ",front -> val);
        i ++;
    }
}

int level(struct node*root){
    if(!root) return 0;
    return 1 + fmax(level(root -> left),level(root -> right));
}

bool checkBalance(struct node* root){
    if(!root) return true;
    if(abs(level(root -> right) - level(root -> left)) > 1) return false;
    return checkBalance(root -> right) && checkBalance(root -> left );
}

struct node* convertSortedArray(int* arr,int l ,int r){
    if(l > r) return NULL;
    int m = (r - l )/2 + l;
    struct node * result = newNode(arr[m]);

    result -> left = convertSortedArray(arr,l,m-1);
    result -> right = convertSortedArray(arr,m+1,r);
    return result;
}

int main()
{
    struct node* root = newNode(-1);
    int *arr = (int*)malloc(100 * sizeof(int));
    for(int i = 0;i <= 20;i ++) arr[i] = i;
    root = convertSortedArray(arr,0,20);
    inorderTraveral(root);
}

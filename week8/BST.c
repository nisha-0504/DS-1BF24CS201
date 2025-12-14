#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
struct Node *createnode(int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}
struct Node *insert(struct Node *root,int value){
    if (root==NULL){
        return createnode(value);
    }
    if(root->data>value){
        root->left=insert(root->left,value);
    }
    else if(root->data<value){
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(struct Node *root){
    if (root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d \n",root->data);
    inorder(root->right);
}
void preorder(struct Node *root){
    if(root==NULL){
        return;
    }
    printf("%d \n",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d \n",root->data);
}
void display(struct Node *root){
    printf("BST elements:");
    inorder(root);
    printf("\n");
}
int main(){
    struct Node *root=NULL;
    int ch=1,val;
    while(ch!=0){
        printf("1:Insert into BST\n");
        printf("2:Inorder Traversal\n");
        printf("3:Preorder Traversal\n");
        printf("4:Postorder Traversal\n");
        printf("5:Display elements\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            {
                int val;
                printf("Enter data:");
                scanf("%d",&val);
                root=insert(root,val);
                break;
            }
            case 2:
            {
                printf("Inorder Traversal\n");
                inorder(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Preorder Traversal\n");
                preorder(root);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("Postorder Traversal\n");
                postorder(root);
                printf("\n");
                break;
            }
            case 5:
            {
                display(root);
                break;
            }
            case 0:
            {
                break;
            }
            default:
            {
                printf("Invalid input");
                break;
            }
        }
    }
}



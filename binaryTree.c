/**********************************************************************/
// Binary trees
/**********************************************************************/
/**********************************************************************/
/*
Depth First Traversals:
(a) Inorder (Left, Root, Right) : 4 2 5 1 3
(b) Preorder (Root, Left, Right) : 1 2 4 5 3
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

Breadth First or Level Order Traversal : 1 2 3 4 5
*/
/**********************************************************************/
// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
     int data;
     struct node* left;
     struct node* right;
};

typedef struct node Node;

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
Node* newNode(int data)
{
     struct node* node = (Node*)malloc(sizeof(Node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}

/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(Node* node)
{
     if (node == NULL)
        return;

     // first recur on left subtree
     printPostorder(node->left);

     // then recur on right subtree
     printPostorder(node->right);

     // now deal with the node
     printf("%d ", node->data);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(Node* node)
{
     if (node == NULL)
          return;

     /* first recur on left child */
     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);

     /* now recur on right child */
     printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(Node* node)
{
     if (node == NULL)
          return;

     /* first print data of node */
     printf("%d ", node->data);

     /* then recur on left sutree */
     printPreorder(node->left);

     /* now recur on right subtree */
     printPreorder(node->right);
}

/**********************************************************************/
//Level order travesal - Breadth first search
/**********************************************************************/
int height(Node* node);
void printGivenLevel(Node* root, int level);

void printLevelOrder(Node* root)
{
  int h = height(root);
  for(int i = 1; i<=h; i++)
  {
    printGivenLevel(root,i);
    printf("\n");
  }
}

int height(Node* root)
{
  if(root == NULL)
    return 0;
  int lheight = height(root->left);
  int rheight = height(root->right);

  if(lheight>rheight)
    return lheight+1;
  else
    return rheight+1;
}

void printGivenLevel(Node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ",root->data);
  else if(level > 1)
  {
    printGivenLevel(root->left,level-1);
    printGivenLevel(root->right,level-1);
  }
}

void printInOrderWORecursion(Node *root)
{

}

int sizeOfTree(Node *root)
{
  if(root == NULL)
    return 0;
  else
  {
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
  }
}

bool isTreeHeightBalanced(Node *root)
{
  int lh; /* for height of left subtree */
  int rh; /* for height of right subtree */

  /* If tree is empty then return true */
  if(root == NULL)
   return 1;

  /* Get the height of left and right sub trees */
  lh = height(root->left);
  rh = height(root->right);

  if( abs(lh-rh) <= 1 &&
      isTreeHeightBalanced(root->left) &&
      isTreeHeightBalanced(root->right))
    return 1;

  /* If we reach here then tree is not height-balanced */
  return 0;
}

int getLeafCount(Node *root)
{
  if(root == NULL)
    return 0;
  if(root->left == NULL && root->right == NULL)
    return 1;
  else
  {
    return getLeafCount(root->left)+getLeafCount(root->right);
  }
}

bool isSumProperty(Node *root)
{
  int left_data,right_data = 0;

  if(root == NULL || (root->left == NULL && root->right == NULL))
    return true;
  else
  {
    if(root->right != NULL)
      right_data = root->right->data;
    if(root->left != NULL)
      left_data = root->left->data;

    if(root->data == left_data + right_data &&
    isSumProperty(root->left) && isSumProperty(root->right))
        return 1;
    else
      return 0;
  }
}

/* Driver program to test above functions*/
int main()
{
     Node *root  = newNode(1);
     root->left             = newNode(2);
     root->right           = newNode(3);
     root->left->left     = newNode(4);
     root->left->right   = newNode(5);

    //  printf("\nPreorder traversal of binary tree is \n");
    //  printPreorder(root);
     //
    //  printf("\nInorder traversal of binary tree is \n");
    //  printInorder(root);
     //
    //  printf("\nPostorder traversal of binary tree is \n");
    //  printPostorder(root);
     //
    //  printf("\nLevelorder traversal of binary tree is \n");
    //  printLevelOrder(root);

    //  printf("Size of tree is %d",sizeOfTree(root));
    //  if(isTreeHeightBalanced(root))
    //   printf("Tree is height balanced");
    //  else
    //  printf("Tree is not height balanced");

    printf("%d",getLeafCount(root));
    if(isSumProperty(root))
      printf("\tYEAH");
     getchar();
     return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1 == 1
#define false 1 != 1

#define size 50
#define sizeofnode 1000

typedef int boolean;
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} TreeNode;
TreeNode* tree[size];

TreeNode* treeinsert(TreeNode* t, int data, int* leftnode, int* rightnode) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode* current = t;
    TreeNode* parent = t;
    if (t == NULL) {
        t = newNode;
    } else {
          boolean flag = false;
          while (!flag) {
              parent = current;
              if (current->key > data) {
                  current = current->left;
                  if (current == NULL) {
                      parent->left = newNode;
                      flag = true;
                  }
              } else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = newNode;
                        flag = true;
                    }
                }
              if (t->key > data)
                  (*leftnode)++;
              else
                  (*rightnode)++;
          }
      }
    return t;
}

void printTree(TreeNode* root)
{
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}
float percent_of_balanced(int* array1, int* array2)
{
    int number_of_balanced = 0;
    for(int i = 0; i < size; ++i)
        if (fabs(array1[i] - array2[i]) <= 1)
            number_of_balanced++;
    float percent = (number_of_balanced * 100.0) / size;
    printf("%d trees balanced from %d trees\n", number_of_balanced, size);
    return percent;
}
void trees()
{

    int left[size];
    int right[size];
    for (int i = 0; i < size; ++i) {
        tree[i] = NULL;
    }
    int leftlevel = 0;
    int rightlevel = 0;
    int maxleft = 0;
    int maxright = 0;
    for (int i = 0; i < size; ++i) {
        int dat = rand() % sizeofnode;
        tree[i] = treeinsert(tree[i], dat, &leftlevel, &rightlevel);
        for (int j = 1; j < sizeofnode; ++j) {
            leftlevel = rightlevel = 0;
            dat = rand() % sizeofnode;
            treeinsert(tree[i], dat, &leftlevel, &rightlevel);
            if (maxleft < leftlevel)
                maxleft = leftlevel;
            if (maxright < rightlevel)
                maxright = rightlevel;
        }
        printf("\n");
        printTree(tree[i]);
        printf("\n\n");
        left[i] = maxleft;
        right[i] = maxright;
        maxleft = maxright = 0;
    }
    printf("%.1f%% balanced trees from %d trees\n", percent_of_balanced(left, right), size);
}
boolean binsearch(TreeNode* root, int value)
{
    if (root == NULL)
        return false;
    else
        if (root->key == value)
            return true;
    TreeNode* current = root;
    boolean found = false;
    while (current->key != value) {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;
        if (current == NULL)
            return false;
    }
    return true;
}

int main()
{
    //TASK 1
    trees();

    //TASK 2  We are looking element in tree[49]
    int element;
    printf("Input integer number 0 - 999 for search: ");
    scanf("%d", &element);
    printf("%d in tree[%d] is %s found\n", element, 49, (binsearch(tree[49], element) ? "" : "not"));

    system("PAUSE");
    return 0;
}

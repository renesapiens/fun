#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};


// Create a tree based on a sorted array. We follow
// a process similar to a binary search where we get
// a new parent node on each recursion. Observe how
// we split the array on each iteration.
struct node* create_tree(int arr[], int start, int end)
{
    if(start > end)
        return NULL;
  
    int mid = (start + end)/2;
    struct node *root = new struct node();
    root->data = arr[mid];
    root->left = create_tree(arr, start, mid-1);
    root->right = create_tree(arr, mid+1, end);
    return root;
}

// Starting from root find the address of the node that
// corresponds to 'data'. If not found return NULL.
struct node* get_node_address(struct node* root, int data)
{
    if(root == NULL)
        return NULL;
    if(root->data == data)
        return root;
    if(root->data < data)
        return get_node_address(root->right, data);
    if(root->data > data)
        return get_node_address(root->left, data);
}

// Starting from a node's address find
// the node deepest in the left.
struct node* get_left(struct node* root)
{
    if(root == NULL)
        return NULL;

    struct node *tmp = root;

    while(tmp->left != NULL) {
         tmp = tmp->left;
     }

     return tmp;
}

// This function handles the different scenarios to
// find the successor:
// Scenario 1:
//    Node to find its successor has a right child.
//    if this is the case we need to find the node
//    deep in the left of this node's right child.
// Scenario 2:
//    Current node has a parent which hasn't been
//    visited. On this case we still need to reach
//    the node to find its successor starting from
//    the root and keep track of the ancestor and
//    successor.
// Scenario 3:
//    We have already visited left children and parent.
//    the successor must be before the node's parent.
struct node* inorder_successor(node *root, int data)
{
    node *cur_node;
    
    // traverse the tree to get the node's address for
    // 'data'.
    cur_node = get_node_address(root, data);
    if(cur_node == NULL)
        return NULL;
    // Case 1: if there is a node in the right child
    // then check if it has left children. If that is
    // the case then get_left will return our successor.
    if(cur_node->right != NULL) {
        return get_left(cur_node->right);
    } else {
        // Case two and three. If node doesn't have a
        // right child then it means that the successor
        // will be a parent or a node above this node's
        // parent.
        node* succ = NULL;
        node* anc = root;
        while(anc != cur_node) {
            if(cur_node->data < anc->data) {
                succ = anc;
                anc = anc->left;
            } else {
                anc = anc->right;
            }
        }
        return succ;
    }
}

//Print the inorder traversal of the tree.
void inorder(struct node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

//Print the preorder of the tree.
void preorder(struct node* root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    // use a sorted array to create the bst.
    int array[] = {9, 11, 13, 14, 15, 18, 21, 22, 25, 30, 32};
    struct node *root;

    //Use the sorted array to create the BST, we will use a procedure
    //similar to binary search to generate the tree.    
    root = create_tree(array, 0, sizeof(array)/sizeof(array[0]) - 1);
    //We are searching for the successor of node 15.
    struct node* node_suc = inorder_successor(root, 15);
    cout << "In order traversal of the tree: ";
    inorder(root);
    cout << endl;
    cout << "The successor is: " << node_suc->data << endl;

    return 0;
}

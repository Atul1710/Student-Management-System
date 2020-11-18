//#include <iostream>
//using namespace std;

//int max(int a, int b)
//{
//    return a>b ? a : b;
//}

//class BinarySearchTree
//{
//    public:
//    int data;
//    BinarySearchTree *left, *right, *parent;

//    // Default constructor.
//    BinarySearchTree()
//    {
//        data = 0;
//        left = NULL;
//        right = NULL;
//        parent = NULL;
//    }
//    // Parameterized constructor.
//    BinarySearchTree(int value)
//    {
//        data = value;
//        left = NULL;
//        right = NULL;
//        parent = NULL;
//    }

////    int getdata()
////    {
////        return data;
////    }

//    // Insert function.
//    BinarySearchTree* insert(BinarySearchTree* root, int value)
//    {
//        if(!root)
//        {
//            // If root is NULL, create a new node and insert it
//            root = new BinarySearchTree(value);
//            return root;
//        }

//        // Insert data to the left of the node if 'value' is lesser than that of the node, else to the right
//        if(value < root->data)
//        {
//            // If the node is a leaf, insert the value else continue traversing
//            if(root->left == NULL)
//            {
//                BinarySearchTree* child = new BinarySearchTree(value);
//                root->left = child;
//                child->parent = root;
//            }
//            else
//            {
//                insert(root->left, value);
//            }
//        }
//        else
//        {
//            // If the node is a leaf, insert the value else continue traversing
//            if(root->right == NULL)
//            {
//                BinarySearchTree* child = new BinarySearchTree(value);
//                root->right = child;
//                child->parent = root;
//            }
//            else
//            {
//                insert(root->right, value);
//            }
//        }
//        return root;
//    }

//    // Find height of a node
//    int height(BinarySearchTree* node)
//    {
//        if(node == NULL)
//        {
//            return 0;
//        }
//        else
//        {
//            int left_side;
//            int right_side;
//            // Return the largest of the heights on either side
//            left_side = height(node->left);
//            right_side = height(node->right);
//            if(left_side > right_side)
//            {
//                return left_side + 1;
//            }
//            else
//            {
//                return right_side + 1;
//            }
//        }
//    }

//     // Find depth of a node
//    int depth(BinarySearchTree* root, BinarySearchTree* node)
//    {
//        // Return 0 if the node is present as a leaf, else -1 if we reach a leaf node that is not the node we are looking for
//        if(root == NULL || root == node)
//        {
//            return 0;
//        }
//        else if(root->left == NULL && root->right == NULL)
//        {
//            return -1;
//        }
//        // Return 1 if the node is the child of the current root
//        if(root->left == node || root->right == node)
//        {
//            return 1;
//        }
//        int left_side;
//        int right_side;
//        left_side = depth(root->left, node);
//        right_side = depth(root->right, node);
//        // If both left side and right side are less than 0, we have reached a leaf node without passing the required node
//        if (left_side < 0 && right_side < 0)
//        {
//            return max(left_side-1, right_side-1);
//        }
//        return max(left_side+1, right_side+1);
//    }

//    // Find the node with minimum value
//    BinarySearchTree* find_min(BinarySearchTree* node)
//    {
//        BinarySearchTree* cur = node;
//        while (cur && cur->left != NULL)
//        {
//            cur = cur->left;
//        }
//        return cur;
//    }

//    // Find the node with maximum value
//    BinarySearchTree* find_max(BinarySearchTree* node)
//    {
//        BinarySearchTree* cur = node;
//        while (cur && cur->right != NULL)
//        {
//            cur = cur->right;
//        }
//        return cur;
//    }

//    // Search function.
//    int search(BinarySearchTree* root, int value)
//    {
//        // End the search if we reach either a leaf or the required node
//        if (root == NULL || root->data == value)
//        {
//            return root->data;
//        }

//        // If value being searched is lesser than that of the current node, continue searching in the left sub-tree
//        if (value < root->data)
//        {
//            return search(root->left, value);
//        }

//        // If value being searched is greater than that of the current node, continue searching in the right sub-tree
//        return search(root->right, value);
//    }



//    // Delete a node.
//    BinarySearchTree* delete_node(BinarySearchTree* root, int value)
//    {
//        // If the current node does not exist, return NULL
//        if (root == NULL)
//        {
//            return root;
//        }
//        // If value of the node to be deleted is lesser than that of the current node, continue searching in the left sub-tree
//        if (value < root->data)
//        {
//            root->left = delete_node(root->left, value);
//        }
//        // If value of the node to be deleted is greater than that of the current node, continue searching in the right sub-tree
//        else if (value > root->data)
//        {
//            root->right = delete_node(root->right, value);
//        }
//        // If the node has been located, link one of its children with its parent before deleting it
//        else
//        {
//            if (root->left == NULL)
//            {
//                BinarySearchTree* temp = root->right;
//                delete root;
//                return temp;
//            }
//            else if (root->right == NULL)
//            {
//                BinarySearchTree* temp = root->left;
//                delete root;
//                return temp;
//            }
//            BinarySearchTree* temp = find_min(root->right);
//            root->data = temp->data;
//            root->right = delete_node(root->right, temp->data);
//        }
//        return root;
//    }

//    // Inorder traversal
//    void inorder(BinarySearchTree *root)
//    {
//        if(!root)
//        {
//            return;
//        }
//        inorder(root->left);
//        cout << root->data << " ";
//        inorder(root->right);
//    }

//    // Preorder traversal
//    void preorder(BinarySearchTree *root)
//    {
//        if (root != NULL)
//        {
//            cout<<root->data<<" ";
//            preorder(root->left);
//            preorder(root->right);
//        }
//    }

//    // Postorder traversal
//    void postorder(BinarySearchTree *root)
//    {
//        if (root != NULL)
//        {
//            postorder(root->left);
//            postorder(root->right);
//            cout<<root->data<<" ";
//        }
//    }

//    // Print the descendants of a node
//    void descendants(BinarySearchTree* node)
//    {
//        if (node == NULL)
//        {
//            cout << "None\n";
//            return;
//        }
//        inorder(node->left);
//        inorder(node->right);
//        cout << endl;
//    }

//    // Print the ancestors of a node
//    void ancestors(BinarySearchTree* node)
//    {
//        node = node->parent;
//        while(node != NULL)
//        {
//            cout << node->data << " ";
//            node = node->parent;
//        }
//        cout << endl;
//    }

//    // Print the successor of a node
//    BinarySearchTree* successor(BinarySearchTree* root, BinarySearchTree* node)
//    {
//        if(node->right != NULL)
//        {
//            return find_min(node->right);
//        }
//        BinarySearchTree* temp = node->parent;
//        while(temp != NULL && node == temp->right)
//        {
//            node = temp;
//            temp = temp->parent;
//        }
//        return temp;
//    }

//    // Print the predecessor of a node
//    BinarySearchTree* predecessor(BinarySearchTree* root, BinarySearchTree* node)
//    {
//        if(node->left != NULL)
//        {
//            return find_max(node->left);
//        }
//        BinarySearchTree* temp = node->parent;
//        while(temp != NULL && node == temp->left)
//        {
//            node = temp;
//            temp = temp->parent;
//        }
//        return temp;
//    }
//};





#include <iostream>
#include <stack>
using namespace std;


class Student{
public:
    struct node{
        int regno;
        string name;
        string fathername;
        float dsa;
        float iwp;
        float networks;
        node *left;
        node *right;
        node *parent;
//        node(){
//            regno = 0;
//            left = NULL;
//            right = NULL;
//            parent = NULL;
//        }
        node(int reg_no, string Name, string fatherName, float dsamarks, float iwpmarks, float networksmarks){
            regno  = reg_no;
            name = Name;
            fathername = fatherName;
            dsa = dsamarks;
            iwp = iwpmarks;
            networks = networksmarks;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
    };
    struct node *root;

    //add student(helper)
    void insert(struct node *Parent, struct node *itr, struct node *NewNode){
        if (itr == NULL)
                {
                    return;
                }
                else
                {
                    if (NewNode->regno > itr->regno)
                    {
                        if (itr->right != NULL)
                        {
                            insert(itr, itr->right, NewNode);
                            return;
                        }
                        itr->right = NewNode;
                        NewNode->parent = itr;
                        return;
                    }
                    else if (NewNode->regno < itr->regno)
                    {
                        if (itr->left != NULL)
                        {
                            insert(itr, itr->left, NewNode);
                            return;
                        }
                        itr->left = NewNode;
                        NewNode->parent = itr;
                        return;
                    }
                    else
                    {
                        return;
                    }
                }
                return;
    }

    //add student
    bool add(int regno, string Name, string fatherName, float dsamarks, float iwpmarks, float networksmarks){
        if(root == NULL){
            root = new node(regno, Name, fatherName, dsamarks, iwpmarks, networksmarks);
            return 1;
        }

        else{
            node *Newnode = new node(regno,Name, fatherName, dsamarks, iwpmarks, networksmarks);
            insert(NULL, root, Newnode);
            return 1;
        }
        return 0;
    }


//    To search for details apart from marks
    stack<string> searchStudent(struct node *node, int regno){
//        if(node == NULL){
//            stack<string> temp;
//            temp.push("null");
//            return temp;
//        }
//        if(regno == node->regno){
//            stack<string> temp;
//            temp.push(node->name);
//            temp.push(node->fathername);
//            temp.push(to_string(node->regno));
// /*           temp.push(to_string(node->dsa));
//            temp.push(to_string(node->iwp));
//            temp.push(to_string(node->networks))*/;

//            return temp;
//        }
//        else if(regno < node->regno){
//           searchStudent(node->left, regno);
//        }
//        else {
//            searchStudent(node->right, regno);
//        }
//        stack<string> temp;
//        temp.push("null");
//        return temp;

        while(node != NULL){
            if(node->regno == regno){
                stack<string> temp;
                temp.push(node->name);
                temp.push(node->fathername);
                temp.push(to_string(node->regno));
                return temp;
            }
            else if(regno < node->regno){
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        stack<string> temp1;
        temp1.push("nope");
        return temp1;
    }

    stack<string> Search(int regno){
        stack<string> temp = searchStudent(root, regno);
        return temp;
    }

//    To search for marks
    stack<float> Search1(int regno){
        stack<float> Marks = SearchMarks(root, regno);
        return Marks;
    }
    stack<float> SearchMarks(struct node *node, int regno){
//        if(regno == node->regno){
//            stack<float> temp;
//            temp.push(node->dsa);
//            temp.push(node->iwp);
//            temp.push(node->networks);
//            return temp;
//        }
//        else if(regno < node->regno){
//           SearchMarks(node->left, regno);
//        }
//        else {
//            SearchMarks(node->right, regno);
//        }
//        stack<float> temp;
//        temp.push(0.0);
//        return temp;

        while(node != NULL){
            if(node->regno == regno){
                stack<float> temp;
                temp.push(node->dsa);
                temp.push(node->iwp);
                temp.push(node->networks);
                return temp;
            }
            else if(regno < node->regno){
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        stack<float> temp1;
        temp1.push(0);
        return temp1;
    }


    bool search1(int regno, struct node *root1){
//        if(root1->regno == regno){
//            return 1;
//        }
//        if(regno < root1->regno){
//            search1(regno, root1->left);
//        }
//        if(regno > root1->regno){
//            search1(regno,root1->right);
//        }
//        if(root1 == NULL){
//            return 0;
//        }

        while(root1 != NULL){
            if(regno == root1->regno){
                return 1;
            }
            else{
                if(regno < root1->regno){
                    root1 = root1->left;
                }
                else{
                    root1 = root1->right;
                }
            }
        }
        return 0;

    }


    bool search(int regno){
        if(search1(regno, root) == 1)
            return 1;
        return 0;
    }

    struct node* minValueNode(struct node* node)
    {
        struct node* current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    bool deleteNode(node *parent,node *itr,int Reg)
        {
            if (!itr)
                return 0;
            else if (Reg < itr->regno)
                return deleteNode(itr,itr->left, Reg);
            else if (Reg > itr->regno)
                return deleteNode(itr,itr->right, Reg);
            else if (Reg == itr->regno)
            {
                if (!itr->left && !itr->right)
                {
                    delete itr;
                    if (parent && parent->left == itr) parent->left = NULL;
                    else if (parent && parent->right == itr) parent->right = NULL;
                    return 1;
                }

                else if (!itr->left && itr->right)
                {
                    if (parent && parent->left == itr)
                    {
                        parent->left = itr->right;
                    }
                    else if (parent && parent->right == itr)
                    {
                        parent->right = itr->right;
                    }
                    return 1;
                }

                else if (itr->left && !itr->right)
                {
                    if (parent && parent->left == itr)
                    {
                        node *tem = parent->left;
                        parent->left = itr->left;
                        delete tem;
                    }
                    else if (parent && parent->right == itr)
                    {
                        node *tem = parent->right;
                        parent->right = itr->left;
                        delete tem;
                    }
                    return 1;
                }
                else
                {
                    node *predecessor = itr->right;
                    node *previous = NULL;
                    while (predecessor && predecessor->left)
                    {
                        previous = predecessor;
                        predecessor = predecessor->left;
                    }
                    itr->regno = predecessor->regno;
                    itr->name= predecessor->name;
                    itr->fathername = predecessor->fathername;
                    itr->dsa = predecessor->dsa;
                    itr->iwp = predecessor->iwp;
                    itr->networks = predecessor->networks;
                    if (previous)
                        deleteNode(previous, predecessor,predecessor->regno);
                    else
                    {
                        node *temp = itr->right;
                        if (itr->right->right)
                            itr->right = itr->right->right;
                        else
                            itr->right = NULL;
                        delete temp;
                    }
                }
                return 1;
            }
            else {
                return 0;
            }
        }

    bool del(int regno){
        if(deleteNode(NULL, root, regno) == 1){
            return 1;
        }
        return 0;
    }



};

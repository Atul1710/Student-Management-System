//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;


//struct node{
//    string name;
//    string fatherName;
//    int regno;
//    float dsaMarks;
//    float iwpMarks;
//    float networksMarks;
//    node *left;
//    node *right;
//    node *parent;

//    node(){
//    name = "";
//    fatherName = "";
//    regno = 0;
//    dsaMarks = 0;
//    iwpMarks = 0;
//    networksMarks = 0;
//    left = NULL;
//    right = NULL;
//    parent = NULL;
//    }

//    node(string Name, string FatherName, int reg, float dsa, float iwp, float networks){
//        name = Name;
//        fatherName = FatherName;
//        regno = reg;
//        dsaMarks = dsa;
//        iwpMarks = iwp;
//        networksMarks = networks;
//        left = NULL;
//        right = NULL;
//        parent = NULL;
//    }
//};

//node *root;


//bool insert1(struct node *Node,string Name, string FatherName, int reg, float dsa, float iwp, float networks){
//    if(Node == NULL){
//       Node = new node(Name, FatherName, reg,  dsa, iwp, networks);
//       return 1;
//    }

//    else{
//        if(reg < Node->regno){
//            if(insert1(Node->left, Name, FatherName, reg, dsa, iwp, networks))
//                return 1;
//            else
//                return 0;
//        }
//        else if(reg > Node->regno){
//            if(insert1(Node->right, Name, FatherName, reg, dsa, iwp, networks))
//                return 1;
//            else
//                return 0;
//        }
//    }
//    return 0;
//}

//void insert2(node *Parent, node *itr, node *NewNode){
//    if(itr == NULL){
//        return ;
//    }

//    else{
//        if(NewNode->regno < itr->regno){
//            if(itr->right != NULL){
//                insert2(itr, itr->right, NewNode);
//                return ;
//            }
//            itr->right = NewNode;
//            NewNode->parent = itr;
//            return ;
//        }
//        else if(NewNode->regno < itr->regno){
//            if(itr->left != NULL){
//                insert2(itr, itr->left, NewNode);
//                return ;
//            }
//            itr->left = NewNode;
//            NewNode->parent = itr;
//            return ;
//        }
//        else{
//            return ;
//        }
//    }
//    return ;

//}

//bool insert(string Name, string FatherName, int reg, float dsa, float iwp, float networks){
//    if(root == NULL){
//        root = new node(Name, FatherName, reg, dsa, iwp, networks);
//        return 1;
//    }
//    else{
//    node *node2 = new node(Name, FatherName, reg, dsa, iwp, networks);
//    insert2(NULL, root, node2);
//    return 1;
//    }
//    return 1;
//}

//bool search(int regno){
//    node *Newnode = root;
//    while(Newnode != NULL){
//        if(regno == Newnode->regno){
//            return 1;
//        }
//        else if(regno < Newnode->regno){
//            Newnode = Newnode->left;
//        }
//        else
//            Newnode = Newnode->right;
//    }
//    return 0;
//}


//stack<float> searchMarks(int Reg){
//    stack<float> temp;
//    node *itr = root;
//    while (itr && itr->regno != Reg)
//    {
//        if (Reg < itr->regno)
//            itr = itr->left;
//        else if (Reg > itr->regno)
//            itr = itr->right;
//    }
//    if (!itr)
//        return temp;
//    temp.push(itr->networksMarks);
//    temp.push(itr->iwpMarks);
//    temp.push(itr->dsaMarks);
//    return temp;
//}

//stack<string> searchStudent(int Reg)
//{
//    stack<string> temp;
//    node *itr = root;
//    while (itr && itr->regno != Reg)
//    {
//        if (Reg < itr->regno)
//            itr = itr->left;
//        else if (Reg > itr->regno)
//            itr = itr->right;
//    }
//    if (!itr)
//        return temp;
//    temp.push( itr->name);
//    temp.push( itr->fatherName);
//    return temp;
//}

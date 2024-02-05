//
// Created by ASinclair on 2022/12/8.
//

#ifndef PARKSYSDESIGN_AVLTREE_H
#define PARKSYSDESIGN_AVLTREE_H

#endif //PARKSYSDESIGN_AVLTREE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
template <class t>
class AVLnode{
public:
    int balance;
    t data;
    AVLnode *right,*left;
    AVLnode():right(nullptr),left(nullptr){}
    AVLnode(t data):balance(0),right(nullptr),left(nullptr),data(data){}
};

template <class t>
class AVLtree{
public:
    AVLnode<t> *root;

public:
    AVLtree();
    ~AVLtree();
    AVLnode<t> *insert(t data,AVLnode<t> *T);
    AVLnode<t> *del(t data, AVLnode<t> *T);
    void destroy(AVLnode<t> *&T);
    int updateBalance(AVLnode<t> *root_node);
    AVLnode<t> *LL(AVLnode<t> *rotate_node);
    AVLnode<t> *LR(AVLnode<t> *rotate_node);
    AVLnode<t> *RR(AVLnode<t> *rotate_node);
    AVLnode<t> *RL(AVLnode<t> *rotate_node);
    t getMaxData(AVLnode<t> *T);
    AVLnode<t> *search(t data, AVLnode<t> *T);
    void inOrder(AVLnode<t> *T);
    void outFile(ostream &out,AVLnode<t> *T);
    void OrderPrint(AVLnode<t> *T);

};

template<class t>
AVLtree<t>::AVLtree() {
    root = nullptr;
}

template<class t>
AVLtree<t>::~AVLtree() {
    destroy(root);
}
//左旋
template<class t>
AVLnode<t> *AVLtree<t>::LL(AVLnode<t> *rotate_node) {
    AVLnode<t> *temp;
    temp = rotate_node->right;
    rotate_node->right = temp->left;
    temp->left = rotate_node;
    //
//    rotate_node->balance = 0;
//    temp->balance = 0;
    //返回左旋后的parent节点
    return temp;
}

template<class t>
AVLnode<t> *AVLtree<t>::RR(AVLnode<t> *rotate_node) {
    AVLnode<t> *temp = rotate_node->left;
    rotate_node->left = temp->right;
    temp->right = rotate_node;
    //
//    rotate_node->balance = 0;
//    temp->balance = 0;
    //

    return temp;
}

template<class t>
AVLnode<t> *AVLtree<t>::LR(AVLnode<t> *rotate_node) {
    rotate_node->left = LL(rotate_node->left);
    return RR(rotate_node);
}

template<class t>
AVLnode<t> *AVLtree<t>::RL(AVLnode<t> *rotate_node) {
    rotate_node->right = RR(rotate_node->right);
    return LL(rotate_node);
}

template<class t>
int AVLtree<t>::updateBalance(AVLnode<t> *root_node) {
    if(root_node->left == nullptr &&root_node->right == nullptr ){
        root_node->balance = 0;
        return 0;
    }
    else if(root_node->left== nullptr && root_node ->right != nullptr){
        root_node->balance = 0 - (abs(updateBalance(root_node->right))+1);
        return root_node->balance;
    }else if(root_node->right == nullptr && root_node->left!= nullptr){
        root_node->balance = abs(updateBalance(root_node->left))+1 - 0;
        return root_node->balance;
    }else{
        // actually it is lbf+1-(rbf+1) but the 1 - 1 consumed
        root_node->balance =abs(updateBalance(root_node->left)) - abs(updateBalance(root_node->right)) ;
        return root_node->balance;
    }
}

template<class t>
AVLnode<t> *AVLtree<t>::insert(t data, AVLnode<t> *T) {
    if(root == nullptr){
        root = new AVLnode<t>(data);
        return root;
    }
    if(T == nullptr){
        T = new AVLnode<t>(data);
        return T;
    }
    if(data < T->data){
        T->left = insert(data, T->left);
        updateBalance(root);
        // rotate->/
        if(T->balance == 2){
            if(T->left->balance == 1){
                T = RR(T);
            }else{
                T = LR(T);
            }
        }
        updateBalance(root);
        return T;
    }else if (data> T->data){
        T->right = insert(data, T->right);
        updateBalance(root);
        if(T->balance == -2){
            if(T->right->balance == 1){
                T = RL(T);
            }else{
                T = LL(T);
            }
        }
        updateBalance(root);
        return T;
    }else{
        // user existed
        return nullptr;
    }



}





template<class t>
void AVLtree<t>::destroy(AVLnode<t> *&T) {
    if(T){
        if(T->left== nullptr && T->right == nullptr) delete T;
        else if(T->left== nullptr && T->right != nullptr) destroy(T->right);
        else if (T->right == nullptr && T->left!= nullptr) destroy(T->left);
        else{
            destroy(T->left);
            destroy(T->right);
            delete T;
        }
    }

}

template<class t>
AVLnode<t> *AVLtree<t>::del(t data, AVLnode<t> *T) {
    if(root == nullptr || T== nullptr){
        return nullptr;
    }
    if(data > T->data){
        T->right = del(data,T->right);
        updateBalance(root);
        //
        if(T->balance == 2){
            if(T->left->balance == 1){
                T = RR(T);
            }else{
                T = LR(T);
            }
        }else if(T->balance == -2){
            if(T->right->balance == 1){
                T = RL(T);
            }else{
                T = LL(T);
            }
        }
        updateBalance(T);
        return T;
        //rotate ->
    }else if(data < T->data){
        T->left = del(data,T->left);
        updateBalance(root);
        if(T->balance == 2){
            if(T->left->balance == 1){
                T = RR(T);
            }else{
                T = LR(T);
            }
        }else if(T->balance == -2){
            if(T->right->balance == 1){
                T = RL(T);
            }else{
                T = LL(T);
            }
        }
        updateBalance(T);
        return T;
    }else{
        // found
        //case 1: being a leaf
        if(T->left== nullptr && T->right == nullptr){
            delete T;
            T = nullptr;
            return NULL;
        }
            //case 2: left node existed but right not
        else if(T->left!= nullptr && T->right == nullptr){
            AVLnode<t> *temp = T->left;
            delete T;
            T = nullptr;
            return temp;
        }
            //case 3: opposite of case 2
        else if(T->left == nullptr && T->right != nullptr){
            AVLnode<t> *temp = T->right;
            delete T;
            T = nullptr;

            return temp;
        }
            // case 4 : both existed
        else{
            t x = getMaxData(T->left);
            T->left = del(x, T->left);
            T->data = x;
            return T;
        }
    }

}

template<class t>
t AVLtree<t>::getMaxData(AVLnode<t> *T) {

    AVLnode<t> *temp;
    while(T!= nullptr){
        temp = T;
        T = T->right;
    }

    return T->data;

}

template<class t>
void AVLtree<t>::inOrder(AVLnode<t> *T) {
    if(T == nullptr) return;
    inOrder(T->left);
    cout<<T->data<<" ";
    inOrder(T->right);
}

template<class t>
void AVLtree<t>::outFile(ostream &out,AVLnode<t> *T) {
    if(T == nullptr) return;
    outFile(out,T->left);
    out<<T->data;
    outFile(out, T->right);
}

//template<class t>
//list <t> getInOderList(AVLnode<t> *T, list<t> obj_list) {
//    if(T->left!= nullptr) getInOderList(T->left);
//    obj_list.push_back(T->data);
//    if(T->right!= nullptr) getInOderList(T->right);
//    return obj_list;
//}

template<class t>
AVLnode<t> *AVLtree<t>::search(t data, AVLnode<t> *T) {
    AVLnode<t> *temp = T;
    while(temp){
        if(temp->data == data) return T;
        else if(temp->data < data) temp = temp->right;
        else temp = temp->left;
    }
    return nullptr;
}

template<class t>
void AVLtree<t>::OrderPrint(AVLnode<t> *T) {
      cout<<T->data;
      cout<<endl;
    if(T->left != nullptr) OrderPrint(T->left);
    if(T->right != nullptr) OrderPrint(T->right);
    cout<<endl;
}






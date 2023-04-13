//
// Created by 36302 on 2023/4/9.
//

#ifndef STUDY_CODE_TREE_H
#define STUDY_CODE_TREE_H
#include <iostream>


template<class T>
class Base_Tree{
protected:
    struct Base_node{
        T data;
        Base_node* parent;
        Base_node* left;
        Base_node* right;
        Base_node(T data, Base_node *parent) : data(data), parent(parent),left(nullptr),right(nullptr) {}
        bool isLeft(){return this == this->parent->left;}
        bool isRight(){return this == this->parent->right;}
    };
    int compare(T e1,T e2){
        if(comp){
            return comp(e1,e2);
        }else{
            if(e1<e2){
                return -1;
            } else if(e1>e2){
                return 1;
            } else{
                return 0;
            }
        }
    }
protected:
    int length;
    Base_node* root;
    int (* comp)(T e1,T e2);
    bool (* vector)();
protected:
    void preOrder(Base_node* node){
        if (node== nullptr)return;
        std::cout<<node->data<<",";
        preOrder(node->left);
        preOrder(node->right);
    }
    void inOrder(Base_node* node){
        if (node== nullptr)return;
        inOrder(node->left);
        std::cout<<node->data<<",";
        inOrder(node->right);
    }
    void postOrder(Base_node* node){
        if (node== nullptr)return;
        postOrder(node->left);
        postOrder(node->right);
        std::cout<<node->data<<",";
    }
    void levelOrder(Base_node* node){

    }
    Base_node* treeNode(T element){
        auto node=root;
        while (node){
            int cmp= compare(element,node->data);
            if (cmp==0)return node;
            else if (cmp<0)node=node->left;
            else node=node->right;
        }
        return nullptr;
    }
    Base_node* prevNode(Base_node* node){
        if(node== nullptr)return nullptr;
        //存下左子树
        auto p=node->left;
        if (p!= nullptr){//左子树存在
            while (p->right!= nullptr){
                p=p->right;
            }//当这个节点不存在右子树,这个节点就是左子树中最大的了
            return p;
        }
        p=node;
        while (p->parent!= nullptr && p->isLeft()){
            p=p->parent;
        }
        return p->parent;
    }
public:
    Base_Tree():length(0),root(nullptr),comp(nullptr){};
    Base_Tree(int (* comp)(T e1,T e2)):length(0),root(nullptr),comp(comp){};
    virtual ~Base_Tree() {
        clear();
    }
    int size(){return length;}
    bool empty(){return length==0;}
    void clear(){
        length=0;
    }
    void add(T element){
        if(root== nullptr){//当一个元素都没有直接添加在根节点
            root=new Base_node(element, nullptr);
        }else{
            auto node=root;
            int cmp=0;
            auto parent=node;
            //准备好探路,比较标记,记录父节点
            while (node){//在叶子(nullptr)节点停下来
                parent=node;//更新父节点
                cmp= compare(element,node->data);
                if(cmp){//非等于
                    cmp>0?node=node->right:node=node->left;
                }else{//等于
                    node->data=element;
                    return;
                }
            }
            if(cmp>0){//根据最后一次比较结果
                parent->right=new Base_node(element,parent);
            } else{
                parent->left=new Base_node(element,parent);
            }
        }
        ++length;//修改元素总量
    }
    void remove(T element){

    }
    bool contains(T element){
        return false;
    }
    void preOrder(){
        preOrder(root);
        std::cout<<std::endl;
    }
    void inOrder(){
        inOrder(root);
        std::cout<<std::endl;
    }
    void postOrder(){
        postOrder(root);
        std::cout<<std::endl;
    }
    void levelOrder(){
        levelOrder(root);
        std::cout<<std::endl;
    }

    Base_node* prevNode(T element){
        return prevNode(treeNode(element));
    }
};
#endif //STUDY_CODE_TREE_H
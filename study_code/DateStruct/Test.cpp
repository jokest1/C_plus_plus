//
// Created by 36302 on 2023/4/6.
//
#include "queue.h"
#include "Array.h"
#include <iostream>
#include <string>
//void printfError(char* error);
void testArray(){
    Line<int>* arrs=new DynamicArray<int>();
    for (int i = 0; i < 30; ++i) {
        arrs->push_back(i);
    }

    if (arrs->size()!=30){
        std::cout<<std::string ("size() error\n")<<std::endl;
    }
    for (int i = 0; i < 10; ++i) {
        arrs->pop_back();
    }
    if (arrs->size()!=20){
        std::cout<<std::string("size() error\n")<<std::endl;
    }
    if(arrs->contains(20)){
        std::cout<<std::string("contains() error\n")<<std::endl;
    }
    arrs->set(5,20);
    if(arrs->get(5)!=20){
        std::cout<<std::string("get() error\n")<<std::endl;
    }
}
/*
void testTree(){
    Base_Tree<int> bst;
    int arr[]={7,4,3,11,9,8,2,5,12};
    for (int i = 0; i < 9; ++i){
        bst.add(arr[i]);
    }
    bst.preOrder();
    bst.inOrder();
    bst.postOrder();
    std::cout << bst.prevNode(5)->data;

}*/
/*
void testDarray(){
    DynamicArray dA;
    createArray(15,&dA);
    if (size(&dA)!=0){
        printfError("size() error\n!");
    }
    for (int i = 0; i < 20; ++i) {
        push_back(i,&dA);
    }
    if (size(&dA)!=20){
        printfError("size() error\n!");
    }
    for (int i = 0; i < 10; ++i) {
        pop_back(&dA);
    }
    if (size(&dA)!=10){
        printfError("size() error\n!");
    }
    if (!contains(2,&dA)){
        printfError("contains() error\n!");
    }
    if (get(1,&dA)!=1){
        printfError("get() error\n!");
    }
    set(5,20,&dA);
    if (get(5,&dA)!=20){
        printfError("get() error\n!");
    }
}*/
void printfError(char* error){
    printf("%s",error);
    exit(-1);
}
void testQue(){
    Dequeue<int> que;
    for (int i = 0; i < 20; ++i) {
        que.push_back(i);
    }
    std::cout<<que.pop_front()<<","<<que.pop_back()<<","<<que.size();
}
int main(){
    testArray();
    return 0;
}
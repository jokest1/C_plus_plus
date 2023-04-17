//
// Created by 36302 on 2023/4/17.
//
#include "test_base.h"
/*
 * 模板中可以使用非通用类型如这里的int来指示数组的大小
 */
template<class T,int len>
class stack{
private:
    T sta[len];
    int top=0;
public:
    bool empty(){
        return top==0;
    }
    bool full(){
        return top==len;
    }
    bool push(T x){
        if (top<len) {
            sta[top++] = x;
            return true;
        }
        return false;
    }
    bool pop(T& x){
        if (empty()){
            return false;
        }
        x=sta[--top];
        return true;
    }
};
int main(){
    stack<int,10> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);
    sta.push(4);
    sta.push(5);
    int i;
    while (!(sta.empty())){
        sta.pop(i);
        cout<<i<<endl;
    }
    return 0;
}
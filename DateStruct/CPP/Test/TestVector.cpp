//
// Created by 36302 on 2023/3/30.
//
#include <iostream>
#include <vector>
#include <string>
#include "vector.h"
using namespace std;
namespace vc{
    template<typename T>
    ostream & operator<<(ostream& os,vector<T> vs){
        os.put('[');
        for (auto item:vs) {
            os<<item<<",";
        }
        os.put(']');
        os<<endl;
        return os;
    }
    vector<string> st1{"C","+","+"};
    vector<string> st2(5,"X");
    vector<string> st3(st1.begin(),st1.end());
    vector<string> st4(st1);
    vector<vector<string>>strs{st1,st2,st3,st4};
    void testCreate(){
        for (auto& item:strs) {
            for (auto & it:item) {
                cout<<it<<",";
            }
            cout<<endl;
        }
    }
    void testGet(){
        cout<<"back()"<<st1.back()<<endl;
        cout<<"end()"<<st1.front()<<endl;
        cout<<"operator[]"<<st1[2]<<endl;
        cout<<"at()"<<st1.at(0)<<endl;
    }
    void testIterator(){
        auto begin=st1.begin();
        auto rbegin=st1.rbegin();
        auto end=st1.end();
        auto rend=st1.rend();
    }
    void testCapacity(){
        cout<<"size()"<<st1.size()<<endl;
        cout<<"empty()"<<st1.empty();
        st1.resize(20,"xx");
        cout<<"resize(20,\"xx\")"<<endl;
        cout<<"capacity()"<<st1.capacity()<<endl;
    }
    void testSet(){
        st1.clear();
        st2.push_back("++");
        st2.pop_back();
        cout<<st2;
        st2.insert(st2.cbegin(),"++");
        cout<<st2;
    }
}
int main(){
//    vc::testCreate();
//    vc::testSet();
    lz::testvector1();
    lz::testvector2();
    lz::testvector3();
    lz::testvector4();
    lz::testvector5();
}

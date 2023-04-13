//
// Created by 36302 on 2023/4/13.
//
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string load="../source/test.txt";
    ofstream fout(load,ios::app);
//    fout<<"1111111111\n";
    cout<<fout.tellp();
    fout<<"9";
    cout<<fout.tellp();


    return 0;
}
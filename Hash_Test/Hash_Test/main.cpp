//
//  main.cpp
//  Hash_Test
//
//  Created by Luo on 16/11/14.
//  Copyright © 2016年 com.aspire. All rights reserved.
//

//  练习哈希表

#include <iostream>

#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;//hash_map

class ClassA
{
    
private:
    int a;
    
public:
    ClassA(int x)
    {
        a = x;
    }
public:
    int getValue() const //静态函数？
    {
        return a;
    }
};


struct equal_A
{

    bool operator()(const ClassA &a, const ClassA &b)const{
        
        return a.getValue() == b.getValue();
    }
};

struct hash_A
{
    size_t operator()(const ClassA &a)const
    {
        return a.getValue();
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    hash_map<ClassA,string,hash_A,equal_A> myMap;
    
    ClassA a = ClassA(111);
    ClassA b = ClassA(123);
    
    myMap[a] = "dddd";
    myMap[b] = "qweqwe";
    
    ClassA c = ClassA(11111);
    
    string a1 = myMap[a];
    string b1 = myMap[b];
    string c1 = myMap[c];
    
    if (c1 == "") {
        cout<<"~~~~~~~~~";
    }
    
    cout<<"a 对应的值" << a1 <<endl;
    cout <<"c 的值" << c1 <<endl;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

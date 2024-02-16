/*
* File: Avl.hpp
* Description: Avl ağacının hpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Stack.hpp"
#include "Node.hpp"

class AVL{
public:
    AVL();
    Stack* stack;
    void Insert(int);
    void setNumber(int);
    int getNumber();
    void Postorder();
    char characterFromInt();
    void clearList();
    ~AVL();
private:
    int Height(Node*);
    bool DeleteNode(Node*&);
    Node* RightRotation(Node*);
    Node* LeftRotation(Node*);
    void PostorderUtil(Node*);
    Node* InsertUtil(Node*, int);
    int sum1;
    Node* root;
    int n;
    int number;
};

#endif
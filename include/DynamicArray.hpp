/*
* File: DynamicArray.hpp
* Description: Avl ağaclarinin adresini tutan dinamik dizinin hpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Avl.hpp"

class DynamicArray {
private:
    AVL** array;
    int capacity;
    int length;
    int count;
public:
    DynamicArray();
    void Add(AVL*);
    void clearElement(int);
    void AllPostOrder();
    void mainFonc();
    void CharacterAllOfAvlTrees();
    ~DynamicArray();
};

#endif
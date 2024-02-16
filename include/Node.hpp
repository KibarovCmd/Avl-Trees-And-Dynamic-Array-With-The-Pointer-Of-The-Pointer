/*
* File: Node.hpp
* Description: Avl ağacının Node'unun hpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int height;
        Node * left;
        Node * right;
        Node(int);
};

#endif
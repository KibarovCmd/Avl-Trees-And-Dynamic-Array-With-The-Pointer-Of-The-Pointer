/*
* File: Node.cpp
* Description: Avl ağacının Node'unun cpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#include "Node.hpp"

#include <iostream>
using namespace std;

Node::Node(int k){
    height = 1;
    key = k;
    left = NULL;
    right = NULL;
}

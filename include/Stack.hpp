/*
* File: Stack.hpp
* Description: Avl ağaclarinin icinde bulunan stacklerin hpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
using namespace std;

class Stack {
    public:
        Stack();
        void push(int);
        int printLastValue();
        void pop();
        void bringBack();
        bool isEmpty();
        void length();
        void doZeroLength();
        ~Stack();
    private:
        void isEnoughArea(int);
        void isEnoughArea2(int);
        int* datas;
        int* datas2;
        int capacity;
        int capacity2;
        int lastPlace2;
        int lastPlace;
};

#endif
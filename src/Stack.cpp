/*
* File: Stack.cpp
* Description: Avl ağaclarinin icinde bulunan stacklerin cpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#include "Stack.hpp"

#include <iostream>
#include <string>
using namespace std;

//Kurucu fonksiyon çalıştırılıyor.
Stack::Stack() {
    datas = nullptr;
    datas2 = nullptr;
    capacity = 0;
    lastPlace = -1;
    capacity2 = 0;
    lastPlace2 = -1;
    isEnoughArea(5);
    isEnoughArea2(5);
}
void Stack::push(int data) {
    if(lastPlace < capacity) {
        isEnoughArea(20);
    }
    if(lastPlace2 < capacity2) {
        isEnoughArea2(20);
    }
    lastPlace++;
    lastPlace2++;
    datas[lastPlace] = data;
    datas2[lastPlace2] = data;
}
int Stack::printLastValue() {
    if(lastPlace != -1) {
        return datas[lastPlace];
    }
    else {
        return -1;
    }
}
void Stack::pop() {
    if(lastPlace != -1) {
        lastPlace--; 
    }
}
//Geri getime fonksiyonu stack yapısını elamanlar silinmeden önceki haline getiriyor.
void Stack::bringBack() {
    for(int i = 0; i < lastPlace2; i++) {
            datas[i] = datas2[i];
        }
        lastPlace = lastPlace2;
    }
bool Stack::isEmpty() {
    if(lastPlace == -1) {
        return true;
    }
    else {
        return false;
    }
}
void Stack::length() {
    if(lastPlace == -1) {
        printLastValue();
    }
    else {
        cout << lastPlace + 1 << endl;
    }
}
//Stack'i sıfırlıyor.
void Stack::doZeroLength() {
    lastPlace = -1;
}
//Icerdeki iki dizi de siliniyor.
Stack::~Stack() {
    delete[] datas;
    delete[] datas2;
}
void Stack::isEnoughArea(int bill) {
    int* newArea = new int[bill + capacity];
    for(int i = 0; i < lastPlace + 1; i++) {
        newArea[i] = datas[i];
    }
    if(datas) {
        delete[] datas;
    }
    datas = newArea;
    capacity += bill;
}
void Stack::isEnoughArea2(int bill) {
    int* newArea = new int[bill + capacity2];
    for(int i = 0; i < lastPlace2 + 1; i++) {
        newArea[i] = datas2[i];
    }
    if(datas2) {
        delete[] datas2;
    }
    datas2 = newArea;
    capacity2 += bill;
}

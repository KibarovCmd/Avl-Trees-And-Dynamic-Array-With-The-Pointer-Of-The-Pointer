/*
* File: DynamicArray.cpp
* Description: Avl ağaclarinin adresini tutan dinamik dizinin cpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#include "DynamicArray.hpp"

#include <iostream>
#include <string>
using namespace std;
//Kurucu ayarlanıyor.
DynamicArray::DynamicArray() {
    capacity = 501;
    length = 0;
    array = new AVL*[capacity];
    count = 1;
}
void DynamicArray::Add(AVL* element) {
    if (length == capacity) {
        AVL** temp = new AVL*[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        capacity *= 2;
    }
    array[length] = element;
    array[length]->setNumber(count);
    count++;
    length++;
}
void DynamicArray::clearElement(int index) {
    AVL** tmp = new AVL*[capacity];
    for(int i = 0; i < index; i++) {
        tmp[i] = array[i];
    }
    for(int i = index + 1; i < length; i++) {
        tmp[i - 1] = array[i];
    }
    delete array[index];
    delete[] array;
    array = tmp;
    length--;
}
//Tüm ağaçların postorderları çalıştırılıyor.
void DynamicArray::AllPostOrder() {
    for(int i = 0; i < length; i++) {
        array[i]->Postorder();
    }
}
//Çıkarma ve silme işlemleri son elamana kadar yapılıyor.
void DynamicArray::mainFonc() {
    cout << endl;
    CharacterAllOfAvlTrees();
    system("cls");
    bool crtcert = true;
    int globalIndex;
    while(length != 1) {
        if(crtcert) {
            int TheMin = array[0]->stack->printLastValue();
            int index = 0;
            for(int i = 0; i < length; i++) {
                if(array[i]->stack->printLastValue() < TheMin) {
                    TheMin = array[i]->stack->printLastValue();
                    index = i;                      
                }
            }
            array[index]->stack->pop();
            if(array[index]->stack->isEmpty()) {
                globalIndex = index;
                crtcert = false;
            }
        }
        if(crtcert) {
            int TheMax = array[0]->stack->printLastValue();
            int index = 0;
            for(int i = 0; i < length; i++) {
                if(array[i]->stack->printLastValue() > TheMax) {
                    TheMax = array[i]->stack->printLastValue();
                    index = i;
                }
            }
            array[index]->stack->pop();
            if(array[index]->stack->isEmpty()) {
                globalIndex = index;
                crtcert = false;                   
            }
        }
        if(!crtcert) {
            clearElement(globalIndex);
            CharacterAllOfAvlTrees();
            crtcert = true;
            system("cls");
            for(int i = 0; i < length; i++) {
                array[i]->stack->bringBack();
            }
        }
    }
    if(length == 1) {
        system("cls");
        cout << endl << "###########################" << endl;
        cout << array[0]->getNumber() << " : ";
        cout << array[0]->characterFromInt();
        cout << endl << "###########################" << endl;
    }
}  
void DynamicArray::CharacterAllOfAvlTrees() {
    for(int i = 0; i < length; i++) {
        cout << array[i]->characterFromInt();
    }
}
//Tüm pointerların avl ağaçları siliniyor daha sonra dizi siliniyor.
DynamicArray::~DynamicArray() {
    for(int i = 0; i < length; i++) {
        delete array[i];
    }
    delete[] array;
}
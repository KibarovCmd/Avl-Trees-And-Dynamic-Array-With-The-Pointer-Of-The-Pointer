/*
* File: Run.cpp
* Description: int main() fonksiyonun cpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#include "DynamicArray.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //Dosyadan okuma yapılıyor ve programa ekleniyor.
    DynamicArray tree;
    ifstream file("Data.txt");
    string line;
    string getLine = "";
    if (file.is_open()) {
        while (getline(file, line)) {
            line += " .";
            AVL* avl = new AVL();
            for(int i = 0; line[i] != '.'; i++) {
                if(line[i] != ' ') {
                    getLine += line[i];
                }
                else {
                    avl->Insert(stoi(getLine));
                    getLine = "";
                }
            }
            tree.Add(avl);
        }
        file.close();
    }
    else {
        file.open("../Data.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                line += " .";
                AVL* avl = new AVL();
                for(int i = 0; line[i] != '.'; i++) {
                    if(line[i] != ' ') {
                        getLine += line[i];
                    }
                    else {
                        avl->Insert(stoi(getLine));
                        getLine = "";
                    }
                }
                tree.Add(avl);
            }
            file.close();
        }
    }
    //Tüm postoderlar okunup main fonksiyonu çalıştırılıyor.
    tree.AllPostOrder();
    tree.mainFonc();
    system("pause");
    return 0;
}
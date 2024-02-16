/*
* File: Avl.cpp
* Description: Avl ağacının cpp dosyasi.
* Course: Birinci öğretim A grubu
* Assignment: 2
* Date: 12.24.2023(Month.Day.Year)
* Author: İskender Musaoğlu iskender.musaoglu@ogr.sakarya.edu.tr
*/

#include "Avl.hpp"

#include <iostream>
#include <string>
using namespace std;

//Kurucu baslatiliyor.
AVL::AVL() {
    root = NULL;
    sum1 = 0;
    stack = new Stack();
}
void AVL::Insert(int x) {
    root=InsertUtil(root, x);
}
void AVL::setNumber(int index) {
    number = index;
}
int AVL::getNumber() {
    return number;
}
//Her çağırımda sum1 ve stack boşaltılıyor.
void AVL::Postorder(){
    sum1 = 0;
    stack->doZeroLength();
    PostorderUtil(root);
    cout << endl;
}
char AVL::characterFromInt() {
    return static_cast<char>(sum1%26 + 65);
}
//Tüm nodelar siliniyor.
void AVL::clearList() {
    if(root == NULL) {
        DeleteNode(root);
    }
}
//İlk önce stack daha sonra tüm nodelar siliniyor yıkıcı çağırıldığı zaman.
AVL::~AVL() {
    delete stack;
    clearList();
}
int AVL::Height(Node* head) {
    if(head==NULL) return 0;
    return head->height;
}
bool AVL::DeleteNode(Node *&subNode) {
    Node *delNode = subNode;
    if(subNode->right == NULL) {
        subNode = subNode->left;
    }
    else if(subNode->left == NULL) {
        subNode = subNode->right;
    }
    else {
        delNode = subNode->left;
        Node *parent = subNode;
        while(delNode->right != NULL) {
            parent = delNode;
            delNode = delNode->right;
        }
        subNode->key = delNode->key;
        if(parent == subNode) {
            subNode->left = delNode->left;
        }
        else {
            parent->right = delNode->left;
        }
    }
    delete delNode;
    return true;
}
Node* AVL::RightRotation(Node* head) {
    Node * newhead = head->left;
    head->left = newhead->right;
    newhead->right = head;
    head->height = 1+max(Height(head->left), Height(head->right));
    newhead->height = 1+max(Height(newhead->left), Height(newhead->right));
    return newhead;
}
Node* AVL::LeftRotation(Node* head) {
    Node * newhead = head->right;
    head->right = newhead->left;
    newhead->left = head;
    head->height = 1+max(Height(head->left), Height(head->right));
    newhead->height = 1+max(Height(newhead->left), Height(newhead->right));
    return newhead;
}
//Önce sol sonra sağ çocuğa giderek yaprak mı diye kontrol ediyor değilse sayısal...
//Değeri sum'a ekleniyor yapraksa stack'e ekleniyor.
//Postorder okuma yapıyor.
void AVL::PostorderUtil(Node* head) {
    int controller = 0;
    if(head != NULL) {
        if(head->left) {
            PostorderUtil(head->left);
        }
        else {
            controller++;
        }
        if(head->right) {
            PostorderUtil(head->right);
        }
        else {
            controller++;
        }
        if(controller == 2) {
            stack->push(head->key);
        }
        else {
            sum1 += head->key;
        }
    }
}
Node* AVL::InsertUtil(Node* head, int x) {
    if(head==NULL){
        n+=1;
        Node* temp = new Node(x);
        return temp;
    }
    if(x < head->key) head->left = InsertUtil(head->left, x);
    else if(x > head->key) head->right = InsertUtil(head->right, x);
    head->height = 1 + max(Height(head->left), Height(head->right));
    int bal = Height(head->left) - Height(head->right);
    if(bal>1){
        if(x < head->left->key){
            return RightRotation(head);
        }else{
            head->left = LeftRotation(head->left);
            return RightRotation(head);
        }
    }else if(bal<-1){
        if(x > head->right->key){
            return LeftRotation(head);
        }else{
            head->right = RightRotation(head->right);
            return LeftRotation(head);
        }
    }
    return head;
}
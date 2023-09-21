#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void khoiTao(Node* &head){
    head=NULL;
}
Node* taoNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->next=NULL;
}
void themNodeVaoCuoi(Node* &head, int data){
    Node* temp=taoNode(data);
    if (head== NULL){
        head=temp;
    }
    else{
        Node* p=head;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
}
void themNodeVaoDau(Node* &head, int data){ 
    Node* temp=taoNode(data);
    if (head == NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void themNodeVaoPos(Node* &head, int data, int pos){
    if (pos<)
}
int main(){

}
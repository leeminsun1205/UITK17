#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
void khoiTao(Tree &root){
    root=NULL;
}
Tree taoNode(int data){
    Tree temp=new Node;
    temp->data=data;
    temp->pLeft=NULL;
    temp->pRight=NULL;
    return temp;
}
void themNode(Tree &root, int data){
    if (root == NULL){
        root=taoNode(data);
    }
    else{
        if (data<root->data){
            themNode(root->pLeft, data);
        }
        else{
            themNode(root->pRight, data);
        }
    }
}
int getHeigh(Tree root){
    if (root==NULL){
        return 0;
    }
    else{
        if (root->pLeft==NULL && root->pRight==NULL){
            return 0;
        }
        else {
            return max(getHeigh(root->pLeft), getHeigh(root->pRight))+1;
        }
    }
}
int main(){
    Tree root;
    khoiTao(root);
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        int data; cin >> data;
        themNode(root, data);
    }
    cout << getHeigh(root);
}
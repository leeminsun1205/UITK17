#include <bits/stdc++.h>
const int MAX = 31;
int arr[MAX];
struct Node{
    int data, chiSo;
    Node* pLeft;
    Node* pRight;
};
typedef Node* Tree;
void khoiTaoCay(Tree root){
    root=NULL;
}
Tree taoNode(int data){
    Tree temp=new Node;
    temp->data=arr[data];
    temp->chiSo=data;
    temp->pLeft=NULL;
    temp->pRight=NULL;
}
void themNodeVaoCay(Tree &root, int data){
    if (root==NULL){
        root=taoNode(data);
    }
    else{
        if (data<root->data){
            themNodeVaoCay(root->pLeft, data);
        }
        else{
            themNodeVaoCay(root->pRight, data);
        }
    }
}
int soNutCon(Tree root, int con[]){
    return (root ? con[root->chiSo] : 0);
}
int soHoanVi(Tree root, int C[][MAX], int con[]){
    con[root->chiSo] = 1;
    if (root->pLeft==NULL && root->pRight==NULL) {
        return 1;
    }
    int hoanviTrai=soHoanVi(root->pLeft, C, con);
    int hoanviPhai=soHoanVi(root->pRight, C, con);
    int conTrai=soNutCon(root->pLeft,con);
    int conPhai=soNutCon(root->pRight,con);
    con[root->chiSo]+=conTrai+conPhai;
    return hoanviTrai*hoanviPhai*C[conTrai+conPhai][conTrai];
}
using namespace std;
int main(){
    // freopen("test.inp", "r", stdin);
    // freopen("test.inp", "r", stdout);
    Tree root;
    khoiTaoCay(root);
    int n, C[MAX][MAX], con[MAX];
    cin >> n;
    for (int i=1; i<=n; i++){
        int x; 
        cin >> x;
        themNodeVaoCay(root, x);
    }
    for (int i=0; i<=30; i++){
        C[i][0]=1;
    }
    for (int i=1; i<=30; i++)
        for (int j=1; j<=i; j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    cout << soHoanVi(root,C,con);
    return 0;
}
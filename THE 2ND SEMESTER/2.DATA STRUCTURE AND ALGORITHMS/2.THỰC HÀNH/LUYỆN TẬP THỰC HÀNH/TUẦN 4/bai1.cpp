#include <iostream>
#include <map>;
using namespace std;
map<int,int> soLan;
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
        soLan[data]=0;
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
void timKiem(Tree root, int data){
    if (root == NULL){
        cout << "Khong tim thay phan tu " << data << " trong cay\n";
    }
    else{
        if (data == root->data){
            cout << "Tim thay phan tu " << data << " trong cay\n";
        }
        else if(data < root->data){
            timKiem(root->pLeft, data);
        }
        else{
            timKiem(root->pRight, data);
        }
    }
}
void timNodeTheMang(Tree &NodeXoa, Tree &NodeThe){
    if (NodeThe->pLeft != NULL){
        timNodeTheMang(NodeXoa, NodeThe->pLeft);
    }
    else {
        NodeXoa->data=NodeThe->data;
        NodeXoa=NodeThe;
        NodeThe=NodeThe->pRight;
    }
}
void xoaNode(Tree &root, int data){
    if (root == NULL){
        return;
    }
    else {
        if (data < root->data){
            xoaNode(root->pLeft, data);
        }
        else if (data > root ->data){
            xoaNode(root->pRight, data);
        }
        else {
            Tree NodeXoa=root;
            if (root->pLeft == NULL){
                root=root->pRight;
            }
            else if (root->pRight == NULL){
                root=root->pLeft;
            }
            else {
                timNodeTheMang(NodeXoa, root->pRight);
            }
            delete NodeXoa;
        }
    }
}
void duyetNLR(Tree root){
    if (root != NULL) {
        cout << root->data << " ";
        soLan[root->data]++;
        duyetNLR(root->pLeft);
        duyetNLR(root->pRight);
    }
}
void duyetLRN(Tree root){
    if (root != NULL ) {
        duyetLRN(root->pLeft);
        duyetLRN(root->pRight);
        cout << root->data << " ";
    }
}
void duyetLNR(Tree root){
    if (root != NULL) {
        duyetLNR(root->pLeft);
        cout << root->data << " ";
        duyetLNR(root->pRight);
    }
}
void xuatNutLa(Tree root){
    if (root!=NULL){
        xuatNutLa(root->pLeft);
        if (root->pLeft==NULL && root->pRight==NULL){
            if (root->data%2==1){
                cout << root->data;
            }
        }
        xuatNutLa(root->pRight);    
    }
}
void Menu(Tree &root){
    int luaChon;
    while(1){
        system("cls");
        cout << "---------------MENU--------------\n";
        cout << "1. Them node vao cay-------------\n";
        cout << "2. Xoa node khoi cay-------------\n";
        cout << "3. Tim kiem node trong cay-------\n";
        cout << "4. Duyen NLR---------------------\n";
        cout << "5. Duyen LRN---------------------\n";
        cout << "6. Duyen LNR---------------------\n";
        cout << "7. Xuat nut la la so le----------\n";
        cout << "0. Ket thuc chuong trinh---------\n";
        cout << "Moi nhap lua chon: ";
        cin >> luaChon;
        if (luaChon <0 || luaChon>7){
            cout << "Lua chon khong hop le!";
            system("pause");
        }
        else if (luaChon==1){
            int data;
            cout << "Nhap gia tri node can them: ";
            cin >> data;
            themNode(root, data);
        }
        else if (luaChon==2){
            int data;
            cout << "Nhap gia tri node can xoa: ";
            cin >> data;
            xoaNode(root, data);
        }
        else if (luaChon==3){
            int data;
            cout << "Nhap gia tri node can tim kiem: ";
            cin >> data;
            timKiem(root, data);
        }
        else if (luaChon==4){
            cout << "Duyet cay theo NLR:\n";
            duyetNLR(root);
            cout << endl;
            for (auto it: soLan){
                cout << "Nut " << it.first << " xuat hien " << it.second << " lan\n";
            }
            system("pause");
        }
        else if (luaChon==5){
            cout << "Duyet cay theo LRN:\n";
            duyetLRN(root);
            cout << endl;
            system("pause");
        }
        else if (luaChon==6){
            cout << "Duyet cay theo LNR:\n";
            duyetLNR(root);
            cout << endl;
            system("pause");
        }
        else if (luaChon==7){
            cout << "Cac nut la so le la: ";
            xuatNutLa(root);
            cout << endl;
            system("pause");
        }
        else {
            cout << "Chuong trinh ket thuc!";
            break;
        }
    }
}
int main(){
    Tree root;
    khoiTao(root);
    Menu(root);
    system("pause");
    return 0;
}
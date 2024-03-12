#include <bits/stdc++.h>  
 
using namespace std;
 
int bst[101];
 
void insert(int data){
    if(bst[1] == 0) {bst[1] = data; return;}
    int root = 1;
    while(root >= 101 || bst[root] != 0){
        if(data < bst[root]){
        //left
        root = 2*root;
        }
        else{
            //right
            root = 2*root + 1; 
        }
    }
    if(root<101) bst[root] = data;
}

int search(int data){
    if(bst[1] == 0) {return -1;}
    int root = 1;
    while(root >= 101 || bst[root] != 0){
        if(data == bst[root]) return root;
        if(data < bst[root]){
        //left
        root = 2*root;
        }
        else{
            //right
            root = 2*root + 1; 
        }
    }
    return -1;
}
 
int main()
{
    insert(5);
    insert(10);
    insert(3);
    insert(11);
    insert(4);
    insert(2);
    cout<<search(4)<<endl;
    cout<<search(11)<<endl;
    cout<<search(12)<<endl;
    for(int i = 0; i < 10; i++ ) cout<<bst[i]<<" "; cout<<endl;
    
    return 0;
}
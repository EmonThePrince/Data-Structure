#include <bits/stdc++.h>  
 
using namespace std;

const int MAX_SIZE = 1e6;
int bst[MAX_SIZE];
 
void insert(int data){
    if(bst[1] == 0) {bst[1] = data; return;}
    int root = 1;
    while(root < MAX_SIZE && bst[root] != 0){
        //if(data == bst[root]) return;  //if the data is not repeated
        if(data < bst[root]){
            //left
            root = 2*root;
        }
        else{
            //right
            root = 2*root + 1; 
        }
    }
    if(root<MAX_SIZE) bst[root] = data;
}

int search(int data){
    if(bst[1] == 0) {return -1;}
    int root = 1;
    while(root < MAX_SIZE && bst[root] != 0){
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

int insertOrSearch(int data){
    if(bst[1] == 0) {bst[1] = data; return -1;}
    int root = 1;
    while(root < MAX_SIZE && bst[root] != 0){
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
    if(root<MAX_SIZE) bst[root] = data;
    return -1;
} 

int main()
{
    //inserting data..
    insert(5);
    insert(10);
    insert(10);  //checking for repeated insertion
    insert(3);
    insert(11);
    insert(4);
    insert(2);
    
    //searching data...
    cout<<search(4)<<endl;
    cout<<search(11)<<endl;
    cout<<search(12)<<endl;
    cout<<insertOrSearch(12)<<endl;
    
    //printing first 10 data in the tree...
    for(int i = 0; i < 35; i++ ) cout<<bst[i]<<" "; cout<<endl;
    
    return 0;
}

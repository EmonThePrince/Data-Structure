#include<bits/stdc++.h>
using namespace std;

int MAX = 100;

bool check(string s, int n){
    int c = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ('0' + n)) return false;
    }
    return true;
}

vector<vector<string>> warshallAlgo(int n, vector<vector<int>> &w){
    vector<vector<string>> paths(n,vector<string> (n));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         paths[i][j].push_back('0' + i);
    //     }
    //     cout<<endl;
    // }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(w[i][j]>w[i][k]+w[k][j] && w[i][k]!= MAX && w[k][j] != MAX){
                    paths[i][j].push_back('0'+k);
                    w[i][j] = w[i][k] + w[k][j];
                }
            }
        }
    }
    return paths;
}


int main(){
    vector<vector<int>> w ={
        {7, 5, MAX, MAX},
        {7, MAX, MAX, 2},
        {MAX, 3, MAX, MAX},
        {4, MAX, 1, MAX}
    };
    vector<vector<string>> paths = warshallAlgo(4, w);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(w[i][j] == MAX) w[i][j] = 0;
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"paths"<<endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int MAX = 100;
bool check(string s, int n){
    for(int i = 0; i<n; i++){
        if(s[i] == ('0' + n)) return false;
    }
    return true;
}

vector<vector<string>> warshallAlgo(int n, vector<vector<int>> &w){
    vector<vector<string>> paths(n,vector<string> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            paths[i][j].push_back('0' + i);
        }
        cout<<endl;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(w[i][j]>w[i][k]+w[k][j]){
                    if(check(paths[i][j],k))paths[i][j].push_back('0'+k);
                    if(check(paths[i][j],j)) paths[i][j].push_back('0' + j);
                }
                else{
                    if(w[i][j] != MAX && check(paths[i][j],j)) paths[i][j].push_back('0' + j);
                }
                w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
            }
        }
    }
    return paths;
}


int main(){
    vector<vector<int>> w ={
        {2, 7, 5, 10},
        {MAX, MAX, MAX, 2},
        {MAX, MAX, MAX, MAX},
        {MAX, MAX, MAX, MAX}
    };
    vector<vector<string>> paths = warshallAlgo(4, w);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(w[i][j] == MAX) w[i][j] = 0;
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<paths[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000000007;

vector<vector<string>> warshallAlgo(int n, vector<vector<int>> &w) {
    vector<vector<string>> paths(n, vector<string>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (w[i][j] != MAX) {
                paths[i][j] = to_string(i) + "->" + to_string(j);
            }
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (w[i][j] > w[i][k] + w[k][j] && w[i][k] != MAX && w[k][j] != MAX) {
                    w[i][j] = w[i][k] + w[k][j];
                    paths[i][j] = paths[i][k] + "->" + paths[k][j];
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

    cout<<"Minimium cost for each edge: "<<endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(w[i][j] == MAX) w[i][j] = 0;
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Paths: "<<endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout<<paths[i][j]<<"     ";
        }
        cout<<endl;
    }

    return 0;
}
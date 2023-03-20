#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax = 505;

int main() {
    int width, height;
    int mat[nax][nax];
    cin >> width >> height;
    for(int i = 1; i <= width; i++){
        for(int j = 1; j <= height; j++){
            mat[i][j] = 100000;
        }
    }
    for(int i = 1; i < nax; i++){
        mat[i][i] = 0;
    }

    for(int w = 1; w <= width; w++){
        for(int h = 1; h <= height; h++){
            for(int cut = 1; cut < w; cut++){
                mat[w][h] = min(mat[w][h], mat[cut][h]+mat[w-cut][h]+1);
            }
            for(int cut = 1; cut < h; cut++){
                mat[w][h] = min(mat[w][h], mat[w][cut]+mat[w][h-cut]+1);
            }

        }
    }
    cout << mat[width][height] << endl;
    return 0;
}
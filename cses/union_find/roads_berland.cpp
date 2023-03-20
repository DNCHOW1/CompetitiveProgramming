#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU() : () {}
};

int main(){
    /*
    Notes
    - Some roads will be good connections, BUT some roads will be useless
    - n-1 lines will describe the roads
    - Output t, # of lines or days to build roads between each city
    - Looks to always be a solution
        + THUS, t <= # of useless roads (BUT, if n-1 lines then how??)
        + Essentially, trying to remove all cycles and make a "linked list"; to do this n-1 edges needed
        + Then t == # useless roads
    */
    return 0;
}
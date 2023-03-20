#include <iostream>
#include <bits/stdc++.h>

#define ii pair<unsigned int, unsigned int>
#define f first
#define s second

using namespace std;

int main(){
    //ifstream cin("test2.txt");
    unsigned int n, m, num;
    cin >> n >> m;
    map<unsigned int, unsigned int> ticket_prices;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(ticket_prices.count(num)){
            ticket_prices[num] = ticket_prices[num] + 1;
        }else{
            ticket_prices.insert(ii(num, 1));
        }
    }

    unsigned int front;
    for(int i = 0; i < m; i++){
        cin >> front;
        if(ticket_prices.count(front)){
            cout << front << endl;
            ticket_prices[front]--;
            if(!ticket_prices[front]){
                ticket_prices.erase(front);
            }
        }else{
            if(!ticket_prices.empty() && front > (ticket_prices.begin()->f)){
                map<unsigned int, unsigned int>::iterator it = --ticket_prices.lower_bound(front);
                cout << it->f << endl;
                it->s--;
                if(it->s == 0){
                    ticket_prices.erase(it->f);
                }

            }else{
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m, n;
vector<int> deck;
int closeSum = 0;
void doProcess(){
    vector<int> deckPermu;
    for (int i = 0; i < m - 3; ++i){
        deckPermu.push_back(0);
    }
    for (int i = 0; i < 3; ++i){
        deckPermu.push_back(1);
    }
    int sum = 0;
    do {
        for (int i = 0; i < m; ++i){
            if (deckPermu[i] == 1){
                sum += deck[i];
            }
        }
        if (sum > closeSum && sum <= n){
            closeSum = sum;
        }
        sum = 0;
    } while (next_permutation(deckPermu.begin(), deckPermu.end()));
}

int main(){
    int card;
    cin >> m >> n;
    for (int i = 0; i < m; ++i){
        cin >> card;
        deck.push_back(card);
    }
    doProcess();
    cout << closeSum << '\n';
    return 0;
}
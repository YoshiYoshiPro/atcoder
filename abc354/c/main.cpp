#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Card {
    int index;
    int strength;
    int cost;
};

int main() {
    int N;
    cin >> N;
    vector<Card> cards(N);

    for (int i = 0; i < N; ++i) {
        cin >> cards[i].strength >> cards[i].cost;
        cards[i].index = i + 1;
    }

    sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
        if (a.strength != b.strength) return a.strength > b.strength;
        return a.cost < b.cost;
    });

    vector<int> remaining;
    int minCost = INT_MAX;

    for (const auto &card : cards) {
        if (card.cost < minCost) {
            remaining.push_back(card.index);
            minCost = card.cost;
        }
    }

    sort(remaining.begin(), remaining.end());

    cout << remaining.size() << endl;
    for (size_t i = 0; i < remaining.size(); ++i) {
        if (i > 0) cout << " ";
        cout << remaining[i];
    }
    cout << endl;

    return 0;
}

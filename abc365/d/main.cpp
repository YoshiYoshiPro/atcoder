#include <iostream>
#include <string>
#include <vector>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<char> takahashi(N);
    int wins = 0;

    for (int i = 0; i < N; i++) {
        char win_hand, draw_hand;
        if (S[i] == 'R') { win_hand = 'P'; draw_hand = 'R'; }
        else if (S[i] == 'P') { win_hand = 'S'; draw_hand = 'P'; }
        else { win_hand = 'R'; draw_hand = 'S'; }

        if (i == 0 || (win_hand != takahashi[i-1] && draw_hand != takahashi[i-1])) {
            takahashi[i] = win_hand;
            wins++;
        } else if (draw_hand != takahashi[i-1]) {
            takahashi[i] = draw_hand;
        } else {
            takahashi[i] = win_hand;
            wins++;
        }
    }

    std::cout << wins << std::endl;

    return 0;
}

#include <iostream>

int main() {
    int N, T, A;
    std::cin >> N >> T >> A;

    int remaining_votes = N - (T + A);
    int votes_needed_to_win = (N / 2) + 1;

    if (T > votes_needed_to_win || A > votes_needed_to_win) {
        std::cout << "Yes" << std::endl;
    } else if (T + remaining_votes >= votes_needed_to_win && A + remaining_votes >= votes_needed_to_win) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }

    return 0;
}

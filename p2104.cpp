#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_cases;
    cin >> n_cases;

    while (n_cases--) {
        vector<int> counts(7);
        for (int i = 1; i <= 6; ++i) {
            cin >> counts[i];
        }

        int boxes = 0;

        // 1. Pack 6x6 blocks
        boxes += counts[6];

        // 2. Pack 5x5 blocks
        boxes += counts[5];
        int space_for_1x1_in_5x5 = counts[5] * 11;

        // 3. Pack 4x4 blocks
        boxes += counts[4];
        int space_for_2x2_in_4x4 = counts[4] * 5;
        int used_2x2_in_4x4 = min(counts[2], space_for_2x2_in_4x4);
        counts[2] -= used_2x2_in_4x4;
        int space_for_1x1_in_4x4 = counts[4] * 20 - used_2x2_in_4x4 * 4;
        space_for_1x1_in_5x5 += space_for_1x1_in_4x4; // Combine 1x1 space

        // 4. Pack 3x3 blocks
        boxes += counts[3] / 4;
        int remaining_3x3 = counts[3] % 4;

        if (remaining_3x3 > 0) {
            boxes += 1;
            int space_in_3x3_box = 36 - remaining_3x3 * 9;
            int space_for_2x2_in_3x3 = space_in_3x3_box / 4;
            int used_2x2_in_3x3 = min(counts[2], space_for_2x2_in_3x3);
            counts[2] -= used_2x2_in_3x3;
            int space_for_1x1_in_3x3 = space_in_3x3_box - used_2x2_in_3x3 * 4;
            space_for_1x1_in_5x5 += space_for_1x1_in_3x3; // Combine 1x1 space
        }

        // 5. Pack remaining 2x2 and 1x1 blocks

        // Use available 1x1 space for 1x1s first
        int used_1x1_in_avail_space = min(counts[1], space_for_1x1_in_5x5);
        counts[1] -= used_1x1_in_avail_space;
        space_for_1x1_in_5x5 -= used_1x1_in_avail_space;

        int can_place_2x2_in_1x1_space = space_for_1x1_in_5x5 / 4;
        int placed_2x2_in_1x1_space = min(counts[2], can_place_2x2_in_1x1_space);
        counts[2] -= placed_2x2_in_1x1_space;
        space_for_1x1_in_5x5 -= placed_2x2_in_1x1_space * 4;

        boxes += counts[2] / 9;
        int remaining_2x2 = counts[2] % 9;

        if (remaining_2x2 > 0) {
            boxes += 1;
            int space_in_2x2_box = 36 - remaining_2x2 * 4;
             space_for_1x1_in_5x5 += space_in_2x2_box; // Add remaining space to 1x1 pool
        }

        int used_1x1_in_new_space = min(counts[1], space_for_1x1_in_5x5);
        counts[1] -= used_1x1_in_new_space;
        space_for_1x1_in_5x5 -= used_1x1_in_new_space;

        if (counts[1] > 0) {
            boxes += ceil((double)counts[1] / 36.0);
        }

        cout << boxes << endl;
    }

    return 0;
}
class Solution {
public:
    int countCollisions(string directions) {
        int n = (int)directions.size();
        int i = 0, j = n - 1;

        // Cars moving left at the very start never collide
        while (i < n && directions[i] == 'L') i++;

        // Cars moving right at the very end never collide
        while (j >= 0 && directions[j] == 'R') j--;

        // In the middle part, every moving car (L or R) will eventually collide
        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (directions[k] != 'S') collisions++; // count L and R only
        }
        return collisions;
    }
};

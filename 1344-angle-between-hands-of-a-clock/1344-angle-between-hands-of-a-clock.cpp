class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = 6 * minutes;
        double hourAngle = 30 * (hour % 12) + 0.5 * minutes;

        double diff = abs(minAngle - hourAngle);
        return min(360 - diff, diff);
    }
};
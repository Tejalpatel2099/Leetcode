class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        double nearestX = clamp(xCenter, x1, x2);
        double nearestY = clamp(yCenter, y1, y2);

        // this is the where it calculate the  circle at this point
        double deltaX = xCenter - nearestX;
        double deltaY = yCenter - nearestY;

        // if it is less than equal to
        return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
    }

};
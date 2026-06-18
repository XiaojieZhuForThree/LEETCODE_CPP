#include <algorithm>
using std::min;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30;
        double minuteAngle = minutes * 6;
        hourAngle += minutes / 2.0;
        double a = abs(hourAngle - minuteAngle);
        return min(a, 360 - a);
    }
};

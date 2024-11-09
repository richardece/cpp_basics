#include <iostream>
#include <cmath>
using namespace std;
enum class PointType {
    cartesian,
    polar
};

#if 0
struct Point {
    // a and b refers to x and y in cartesian
    // a and b refers to rho and theta for polar
    Point(float a, float b, PointType type = PointType::cartesian)   {
        if (type == PointType::cartesian) {
            x = a;
            y = b;
        } else {
            x = a * cos(b);
            y = a * sin(b);
        }
    }

    float x, y;
};
#endif

class Point {
    Point(float x, float y) : x(x), y(y) {}

public:
        float x, y;
        static Point newCartesian(float x, float y) {
            return {x, y};
        }
        static Point newPolar(float r, float theta){
            return{r * cos(theta), r * sin(theta)};
        }
    //Ctrl+N, auto-generate output stream operator
    friend ostream &operator<<(ostream &os, const Point &point) {
        os << "x: " << point.x << " y: " << point.y;
        return os;
    }
};

int main() {
    std::cout << "Hello, factory!" << std::endl;
    auto p = Point::newCartesian(3,5);
    cout << p <<endl;

    return 0;
}
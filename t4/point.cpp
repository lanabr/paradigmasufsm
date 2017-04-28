#include <iostream>
#include <cmath>

class Point{
private:
    double x;
    double y;
public:
    Point(){
        x = y = 0;
    }
    void construtor(double xi, double yi){
        x = xi;
        y = yi;
    }
    void move(double dx, double dy){
        x = x + dx;
        y = y + dy;
    }
    void distanceTo(Point *p2){
        double d = sqrt(((p2->x - x)*(p2->x - x)) + ((p2->y - y)*(p2->y - y)));
        std::cout << "Distancia entre os pontos (" << x << ", " << y;
        std::cout << ") e (" << p2->x << ", " << p2->y << "): " << d << std::endl;
    }
};

int main()
{
    Point p;
    p.construtor(3, 4);

    Point *pts;
    pts = new Point[5];

    for(int i = 0; i < 5; i++)
        pts[i].construtor(i + 4, i + 3);

    for(int i = 0; i < 5; i++)
        p.distanceTo(&pts[i]);

    delete [] pts;

    return 0;
}

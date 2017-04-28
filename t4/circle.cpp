#include <iostream>
#include <cmath>

const double PI = 3.14159;

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
    double distanceTo(Point *p2){
        return sqrt(((p2->x - x)*(p2->x - x)) + ((p2->y - y)*(p2->y - y)));
    }
    void imprime(){
        std::cout << "centro (" << x << ", " << y << ")";
    }
};

class Circle{
private:
    Point p;
    double r;
public:
    Circle() {
        p = Point();
        r = 0.0;
    }
    void construtor(double xi, double yi, double ri){
        p.construtor(xi, yi);
        r = ri;
    }
    double area() {
        return PI * r * r;
    }
    void setRadius(double radius){
        r = radius;
    }
    void imprime(){
        p.imprime();
        std::cout <<" e raio: " << r;
    }
    void distanceTo(Circle *c2){
        std::cout << "Distancia entre os circulos com ";
        imprime();
        std::cout << " e com ";
        c2->imprime();
        std::cout << " = " << p.distanceTo(&c2->p) - (r + c2->r) << std::endl;
    }
};

int main()
{
   Circle c1;
   Circle* c2 = new Circle();

   c1.construtor(5, 10, 1);
   c2->construtor(3, 3, 1);

   c1.distanceTo(c2);

   delete c2;
}

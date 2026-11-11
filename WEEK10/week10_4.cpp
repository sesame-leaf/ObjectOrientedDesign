#include <iostream>

using std::cout;
using std::endl;


class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
    virtual ~DrawAPI() = default;
};


class RedCircle: public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", y: " << y << " ]" << endl;
    }
};


class GreenCircle: public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", y: " << y << " ]" << endl;
    }
};


class Shape {
protected:
        DrawAPI* drawAPI;
        Shape(DrawAPI* drawAPI) { this->drawAPI = drawAPI; }
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};


class Circle: public Shape {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI): Shape(drawAPI) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void draw() override { drawAPI->drawCircle(radius, x, y); }
};


int main() {
    DrawAPI* redDrawer = new RedCircle();
    Shape* redCircle = new Circle(100, 100, 10, redDrawer);

    DrawAPI* greenDrawer = new GreenCircle();
    Shape* greenCircle = new Circle(100, 100, 10, greenDrawer);

    redCircle->draw();
    greenCircle->draw();

    delete redCircle;
    delete greenCircle;
    delete redDrawer;
    delete greenDrawer;

    return 0;
}
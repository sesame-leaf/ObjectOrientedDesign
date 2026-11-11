#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::transform;
using std::tolower;


class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};


class RoundedRectangle: public Shape {
public:
    void draw() override { cout << "Inside RoundedRectangle::draw() method." << endl; }
};


class RoundedSquare: public Shape {
public:
    void draw() override { cout << "Inside RoundedSquare::draw() method." << endl; }
};


class Rectangle: public Shape {
public:
    void draw() override { cout << "Inside Rectangle::draw() method." << endl; }
};


class Square: public Shape {
public:
    void draw() override { cout << "Inside Square::draw() method." << endl; }
};


class AbstractFactory {
public:
    virtual Shape* getShape(string shapeType) = 0;
    virtual ~AbstractFactory() = default;
protected:
    bool equalsIgnoreCase(string s1, string s2) {
        transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c) {return tolower(c);});
        transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c) {return tolower(c);});
        return s1 == s2;
    }
};


class ShapeFactory: public AbstractFactory {
public:
    Shape* getShape(string shapeType) override {
        if (equalsIgnoreCase(shapeType, "RECTANGLE")) {
            return new Rectangle();
        } else if (equalsIgnoreCase(shapeType, "SQUARE")) {
            return new Square();
        }
        return nullptr;
    }
};


class RoundedShapeFactory: public AbstractFactory {
public:
    Shape* getShape(string shapeType) override {
        if (equalsIgnoreCase(shapeType, "RECTANGLE")) {
            return new RoundedRectangle();
        } else if (equalsIgnoreCase(shapeType, "SQUARE")) {
            return new RoundedSquare();
        }
        return nullptr;
    }
};


class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool rounded) {
        if (rounded) {
            return new RoundedShapeFactory();
        } else {
            return new ShapeFactory();
        }
    }
};


int main() {
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);

    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();

    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();

    AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);

    Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
    shape3->draw();

    Shape* shape4 = shapeFactory1->getShape("SQUARE");
    shape4->draw();

    delete shapeFactory;
    delete shapeFactory1;
    delete shape1;
    delete shape2;
    delete shape3;
    delete shape4;

    return 0;
}
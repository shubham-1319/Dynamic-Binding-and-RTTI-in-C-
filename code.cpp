#include <iostream>
#include <typeinfo>

class Shape {
public:
    virtual void display() const {
        std::cout << "This is a Shape" << std::endl;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void display() const override {
        std::cout << "This is a Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void display() const override {
        std::cout << "This is a Rectangle" << std::endl;
    }
};

int main() {
    const int arraySize = 4;
    Shape* shapes[arraySize];

    Circle circle1;
    Circle circle2;
    Rectangle rectangle1;
    Rectangle rectangle2;

    shapes[0] = &circle1;
    shapes[1] = &circle2;
    shapes[2] = &rectangle1;
    shapes[3] = &rectangle2;

    for (int i = 0; i < arraySize; ++i) {
        // Using typeid() to identify the type
        std::cout << "Object at index " << i << " is of type: " << typeid(*shapes[i]).name() << std::endl;

        // Using dynamic_cast to check the type at runtime
        if (dynamic_cast<Circle*>(shapes[i]) != nullptr) {
            std::cout << "It is a Circle." << std::endl;
        } else if (dynamic_cast<Rectangle*>(shapes[i]) != nullptr) {
            std::cout << "It is a Rectangle." << std::endl;
        } else {
            std::cout << "It is a Shape or an unknown type." << std::endl;
        }

        // Displaying the object's information
        shapes[i]->display();
        std::cout << std::endl;
    }

    return 0;
}

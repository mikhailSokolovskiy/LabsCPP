#include <iostream>
#include <cmath>

// Базовый класс Shape
class Shape {
protected:
    int x, y;  // Позиция фигуры

public:
    Shape(int x, int y) : x(x), y(y) {}

    // Виртуальная функция для рисования
    virtual void draw() = 0;

    // Виртуальная функция для перемещения
    virtual void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    virtual ~Shape() {}
};

// Класс Circle, наследующий от Shape
class Circle : public Shape {
private:
    int radius;  // Радиус круга

public:
    Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {}

    // Переопределение функции рисования для круга
    void draw() override {
        std::cout << "Drawing a circle at (" << x << ", " << y << ") with radius " << radius << std::endl;
    }

    // Переопределение функции перемещения для круга
    void move(int dx, int dy) override {
        Shape::move(dx, dy);
        std::cout << "Moved circle to (" << x << ", " << y << ")" << std::endl;
    }
};

// Класс Rectangle, наследующий от Shape
class Rectangle : public Shape {
private:
    int width, height;  // Ширина и высота прямоугольника

public:
    Rectangle(int x, int y, int width, int height) : Shape(x, y), width(width), height(height) {}

    // Переопределение функции рисования для прямоугольника
    void draw() override {
        std::cout << "Drawing a rectangle at (" << x << ", " << y << ") with width " << width << " and height " << height << std::endl;
    }

    // Переопределение функции перемещения для прямоугольника
    void move(int dx, int dy) override {
        Shape::move(dx, dy);
        std::cout << "Moved rectangle to (" << x << ", " << y << ")" << std::endl;
    }
};

// Основная программа
int main() {
    // Создаем объекты круга и прямоугольника
    Shape* shape1 = new Circle(10, 20, 5);
    Shape* shape2 = new Rectangle(30, 40, 100, 50);

    // Рисуем фигуры
    shape1->draw();
    shape2->draw();

    // Перемещаем фигуры
    shape1->move(5, 10);
    shape2->move(-10, -20);

    // Рисуем фигуры снова после перемещения
    shape1->draw();
    shape2->draw();

    // Освобождаем память
    delete shape1;
    delete shape2;

    return 0;
}
#include <iostream>
#include <locale.h>
#include <string>

class Figure {
protected:
    int sides_count;
    std::string name;
public:
    Figure() {
        sides_count = 0;
        name = "Фигура";
    }
    int get_sides_count() { return sides_count; }
    std::string get_name() { return name; }

    virtual void print_info() {
        std::cout << name << ": " << std::endl;

        if (bool_check()) { std::cout << "Правильная" << std::endl; }
            else { std::cout << "Неправильная" << std::endl; }

        std::cout << "Количество сторон: " << sides_count << std::endl;
    }
    virtual bool bool_check() {
        if (sides_count == 0) { 
            return true; 
        } else { 
            return false; 
        }
    }
};

//*****************************************ТРЕУГОЛЬНИКИ******************************************************

class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle() {
        name = "Треугольник";
        sides_count = 3;
        a = 10, b = 20, c = 30, A = 50, B = 60, C = 70;
    }
    void print_info() override {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
    }
    bool bool_check() override {
        if ((sides_count = 3) && (A + B + C == 180)) {
            return true;
        } else {
            return false;
        }
    }
};

class Right_Triangle : public Triangle {
public:
    Right_Triangle() {
        name = "Прямоугольный треугольник";
        C = 90;
    }
    void print_info() override {
        Triangle::print_info();
    }
    bool bool_check() override {
        if ((C == 90) && (Triangle::bool_check())) { 
            return true; 
        } else { 
            return false; 
        }
    }
};

class Isosceles_Triangle : public Triangle {
public:
    Isosceles_Triangle() {
        name = "Равнобедренный треугольник";
        c = a;
        C = A;
    }
    void print_info() override {
        Triangle::print_info();
    }
    bool bool_check() override {
        if ((a == c) && (A == C) && (Triangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

class Equilateral_Triangle : public Triangle {
public:
    Equilateral_Triangle() {
        name = "Равносторонний треугольник";
        a = c; b = c;
        A = B; C = B;
    }
    void print_info() override {
        Triangle::print_info();
    }
    bool bool_check() override {
        if ((a == b) && (a == c) && (A == 60) && (B == A) && (C == A) && (Triangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

//*****************************************ЧЕТЫРЕХУГОЛЬНИКИ**************************************************

class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle() {
        name = "Четырёхугольник";
        sides_count = 4;
        a = 10, b = 20, c = 30, d = 40, A = 50, B = 60, C = 70, D = 80;
    }
    void print_info() override {
        std::cout << std::endl;
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
    bool bool_check() override {
        if ((sides_count = 4) && (A + B + C + D == 360)) {
            return true;
        } else {
            return false;
        }
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle() {
        name = "Прямоугольник";
        c = a; d = b;
        A = 90; B = 90; C = 90; D = 90;
    }
    void print_info() override {
        Quadrangle::print_info();
    }
    bool bool_check() override {
        if ((a == c) && (b == d) && (A == 90) && (A == B) &&
            (A == C) && (A == D) && (Quadrangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

class Square : public Rectangle {
public:
    Square() {
        name = "Квадрат";
        c = b; a = b;
    }
    void print_info() override {
        Quadrangle::print_info();
    }
    bool bool_check() override {
        if ((a == b) && (Rectangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

class Parallelogram : public Rectangle {
public:
    Parallelogram() {
        name = "Параллелограмм";
        A = 30; C = A;
        B = 40; D = B;
    }
    void print_info() override {
        Quadrangle::print_info();
    }
    bool bool_check() override {
        if ((A == C) && (B == D) && (Rectangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() {
        name = "Ромб";
        a = 30; b = a; c = a; d = a;
    }
    void print_info() override {
        Quadrangle::print_info();
    }
    bool bool_check() override {
        if ((a == b) && (a == c) && (a == d) && (A == C) && (B == D) && (Quadrangle::bool_check())) {
            return true;
        } else {
            return false;
        }
    }
};

//************************************************МЕЙН*******************************************************

int main() {
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Right_Triangle right_triangle;
    Isosceles_Triangle isosceles_triangle;
    Equilateral_Triangle equilateral_triangle;

    Quadrangle quadrangle;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhombus rhombus;

    figure.print_info();
    Figure* fig_triangle = &triangle; fig_triangle->print_info();
    Triangle* tri_right_triangle = &right_triangle; tri_right_triangle->print_info();
    Triangle* tri_isosceles_triangle = &isosceles_triangle; tri_isosceles_triangle->print_info();
    Triangle* tri_equilateral_triangle = &equilateral_triangle; tri_equilateral_triangle->print_info();
    Figure* fig_quadrangle = &quadrangle; fig_quadrangle->print_info();
    Quadrangle* quad_rectangle = &rectangle; quad_rectangle->print_info();
    Quadrangle* quad_square = &square; quad_square->print_info();
    Quadrangle* quad_parallelogram = &parallelogram; quad_parallelogram->print_info();
    Quadrangle* quad_rhombus = &rhombus; quad_rhombus->print_info();

    return 0;
}
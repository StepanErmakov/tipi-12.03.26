#include <iostream>
#include <clocale>
#include <string>

using namespace std;

class Rectangle {
private:
    const double width;
    const double height;
    double area;
    double perimeter;

public:
    // конструктор с параметрами
    Rectangle(double w, double h)
        : width(w), height(h),
        area(w* h),
        perimeter(2 * (w + h)) {
        cout << ">> создан прямоугольник: " << w << " x " << h << endl;
        cout << "   площадь = " << area << ", периметр = " << perimeter << endl;
    }

    // конструктор копирования
    Rectangle(const Rectangle& other)
        : width(other.width),
        height(other.height),
        area(other.area),
        perimeter(other.perimeter) {
        cout << ">> скопирован прямоугольник: " << width << " x " << height << endl;
        cout << "   площадь = " << area << ", периметр = " << perimeter << endl;
    }

    // деструктор
    ~Rectangle() {
        cout << ">> прямоугольник " << width << " x " << height << " уничтожен" << endl;
    }

    // геттеры
    double getwidth() const {
        return width;
    }

    double getheight() const {
        return height;
    }

    double getarea() const {
        return area;
    }

    double getperimeter() const {
        return perimeter;
    }

    // метод для вывода инфы
    void displayinfo() const {
        cout << "прямоугольник:" << endl;
        cout << "  ширина   : " << width << endl;
        cout << "  высота   : " << height << endl;
        cout << "  площадь  : " << area << endl;
        cout << "  периметр : " << perimeter << endl;
        cout << "-------------------" << endl;
    }
};

// функция для разделителя
void printseparator(const string& title) {
    cout << endl;
    cout << "=== " << title << " ===" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    printseparator("начало работы");

    // создаем прямоугольники
    cout << "\n--- создаем прямоугольники ---" << endl;

    Rectangle r1(5.0, 3.0);
    Rectangle r2(10.5, 4.2);
    Rectangle r3(2.2, 2.2);

    printseparator("вывод информации");

    cout << "\nинформация о r1:" << endl;
    r1.displayinfo();

    cout << "\nинформация о r2:" << endl;
    r2.displayinfo();

    cout << "\nинформация о r3 (квадрат):" << endl;
    r3.displayinfo();

    printseparator("копирование");

    // копируем
    Rectangle r4 = r1;
    cout << "\nинформация о копии r4 (копия r1):" << endl;
    r4.displayinfo();

    printseparator("доступ через геттеры");

    cout << "\nпараметры r2 через геттеры:" << endl;
    cout << "  ширина = " << r2.getwidth() << endl;
    cout << "  высота = " << r2.getheight() << endl;
    cout << "  площадь = " << r2.getarea() << endl;
    cout << "  периметр = " << r2.getperimeter() << endl;

    printseparator("массив прямоугольников");

    // массив прямоугольников (без избыточной памяти)
    Rectangle rects[] = {
        Rectangle(1.0, 2.0),
        Rectangle(3.0, 4.0),
        Rectangle(5.0, 6.0)
    };

    cout << "\nвывод массива прямоугольников:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "rects[" << i << "]:" << endl;
        rects[i].displayinfo();
    }

    printseparator("проверка вычислений");

    // проверка
    Rectangle test(4.0, 5.0);
    cout << "\nтестовый прямоугольник 4x5:" << endl;
    cout << "  ожидаемая площадь: 20" << endl;
    cout << "  реальная площадь : " << test.getarea() << endl;
    cout << "  ожидаемый периметр: 18" << endl;
    cout << "  реальный периметр : " << test.getperimeter() << endl;

    printseparator("завершение работы");
    cout << "\nобъекты будут уничтожены автоматически" << endl;

    return 0;
}
#include <iostream>
#include <clocale>
using namespace std;
class Point2D {
private:
    int x;
    int y;

    static int pointcount; //читaем точки

public:
    //конструктор с параметрами
    Point2D(int xcoord, int ycoord) {
        x = xcoord;
        y = ycoord;
        pointcount++;
        cout << ">>конструктор с параметрами: точка (" << x << ", " << y << ")" << endl;
        cout << "   теперь точек: " << pointcount << endl;
    }

    //копирующий конструктор
    Point2D(const Point2D& other) {
        x = other.x;
        y = other.y;
        pointcount++;
        cout << ">>конструктор копирования: создана копия (" << x << ", " << y << ")" << endl;
        cout << "   теперь точек: " << pointcount << endl;
    }

    //деструктор
    ~Point2D() {
        pointcount--;
        cout << ">>деструктор: точка (" << x << ", " << y << ") уничтожена" << endl;
        cout << "   осталось точек: " << pointcount << endl;
    }

    static int getpointcount() {
        return pointcount;
    }

    void show() const { //мтод для вывода
        cout << "[" << x << ";" << y << "]";
    }
};

//инициализация статика
int Point2D::pointcount = 0;

//функция для демонстрации передачи по значению
void somefunction(Point2D p) {
    cout << "   --- внутри somefunction ---" << endl;
    cout << "   получили точку: ";
    p.show();
    cout << endl;
    cout << "   точек сейчас: " << Point2D::getpointcount() << endl;
    cout << "   --- выходим из функции ---" << endl;
} //тут p удалится

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=====================================" << endl;
    cout << "    ТЕСТИРОВАНИЕ КЛАССА Point2D     " << endl;
    cout << "=====================================" << endl;
    cout << "точек в начале: " << Point2D::getpointcount() << endl;
    cout << endl;

    //1
    cout << "--- СОЗДАЕМ p1 ---" << endl;
    Point2D p1(3, 5);
    cout << endl;

    //2 прямая инициализация
    cout << "--- СОЗДАЕМ p2 через копирование  ---" << endl;
    Point2D p2(p1); // так копируем
    cout << endl;

    //3 копирование при создании
    cout << "--- СОЗДАЕМ p3 через = ---" << endl;
    Point2D p3 = p1; // тут тоже конструктор копирования а не оператор присваивания
    cout << endl;

    //4
    cout << "--- СОЗДАЕМ p4 ---" << endl;
    Point2D p4(10, 20);
    cout << "присваиваем p4 = p2 (просто так)" << endl;
    p4 = p2; //присваивание, конструктор не вызывается
    cout << endl;

    //проверка
    cout << "--- ЧТО ИМЕЕМ ---" << endl;
    cout << "всего объектов: " << Point2D::getpointcount() << endl;
    cout << "p1 = "; p1.show(); cout << endl;
    cout << "p2 = "; p2.show(); cout << endl;
    cout << "p3 = "; p3.show(); cout << endl;
    cout << "p4 = "; p4.show(); cout << endl;
    cout << endl;

    // передача в функцию
    cout << "--- ПЕРЕДАЕМ p1 В ФУНКЦИЮ ПО ЗНАЧЕНИЮ ---" << endl;
    cout << "до вызова функции точек: " << Point2D::getpointcount() << endl;

    somefunction(p1); //должна создать копию

    cout << "после вызова функции точек: " << Point2D::getpointcount() << endl;
    cout << endl;

    //динамическая память
    cout << "--- РАБОТА С ДИНАМИЧЕСКОЙ ПАМЯТЬЮ ---" << endl;
    Point2D* p5 = new Point2D(7, 8);
    cout << "точек после new: " << Point2D::getpointcount() << endl;
    cout << "удаляем p5" << endl;
    delete p5;
    cout << "точек после delete: " << Point2D::getpointcount() << endl;
    cout << endl;

    cout << "--- ЗАВЕРШЕНИЕ ---" << endl;
    cout << "точек перед выходом: " << Point2D::getpointcount() << endl;
    cout << "сейчас все автоматически уничтожится:" << endl;
    

    return 0;
}
#include <iostream>
#include <clocale>
using namespace std;

class Temperature {
private:
    double celsius;   //температура в цельсиях 
    char scale;       //исходная шкала 

public:
    //конструктор от double
    explicit Temperature(double c)
        : celsius(c), scale('C') {
        cout << ">> конструктор от double (явный): " << c << "°C" << endl;
    }

    //конструктор от double и char
    Temperature(double value, char s) {
        scale = s;
        //преобразуем всё в цельсии для хранения
        if (s == 'C' || s == 'c') {
            celsius = value;
            cout << ">> конструктор от double и char: " << value << "°C (уже цельсии)" << endl;
        }
        else if (s == 'F' || s == 'f') {
            celsius = (value - 32.0) * 5.0 / 9.0;
            cout << ">> конструктор от double и char: " << value << "°F -> " << celsius << "°C" << endl;
        }
        else if (s == 'K' || s == 'k') {
            celsius = value - 273.15;
            cout << ">> конструктор от double и char: " << value << "K -> " << celsius << "°C" << endl;
        }
        else {
            cout << ">> неизвестная шкала '" << s << "', считаем что это цельсии" << endl;
            celsius = value;
            scale = 'C';
        }
    }

    // деструктор
    ~Temperature() {
        cout << ">> деструктор для температуры " << celsius << "°C" << endl;
    }

    //метод для получения в фаренгейтах
    double tofahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }

    //геттер для цельсиев
    double getcelsius() const {
        return celsius;
    }

    //геттер для шкалы
    char getscale() const {
        return scale;
    }

    //метод для вывода инфы
    void show() const {
        cout << "температура: " << celsius << "°C";
        cout << " (исходная шкала: " << scale << ")" << endl;
    }
};

//функция которая выводит температуру кипения воды в фаренгейтах
void printboilingpoint(Temperature t) {
    cout << "\n--- внутри printboilingpoint ---" << endl;
    cout << "температура кипения воды (100°C) в фаренгейтах: " << t.tofahrenheit() << "°F" << endl;
    cout << "--- выходим из функции ---" << endl;
} //тут t удалится

//маленькая функция для разделителя
void sep(const string& text) {
    cout << "\n=== " << text << " ===" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    sep("НАЧАЛО");

    cout << "попытка вызвать printboilingpoint(100.0):" << endl;
    cout << "если раскомментить - будет ошибка компиляции из-за explicit" << endl;
    cout << "   (строку закомментили чтоб код компилировался)" << endl;

    sep("ЯВНЫЙ ВЫЗОВ");
    cout << "вызываем printboilingpoint(temperature(100.0)):" << endl;
    printboilingpoint(Temperature(100.0));

    //создаем объекты с разными шкалами
    sep("ОБЪЕКТЫ С РАЗНЫМИ ШКАЛАМИ");

    cout << "\nсоздаем температуру 100°F:" << endl;
    Temperature t1(100.0, 'F');
    cout << "в фаренгейтах: " << t1.tofahrenheit() << "°F" << endl;
    cout << "в цельсиях: " << t1.getcelsius() << "°C" << endl;

    cout << "\nсоздаем температуру 373.15K:" << endl;
    Temperature t2(373.15, 'K');
    cout << "в фаренгейтах: " << t2.tofahrenheit() << "°F" << endl;
    cout << "в цельсиях: " << t2.getcelsius() << "°C" << endl;

    cout << "\nсоздаем температуру 0°C:" << endl;
    Temperature t3(0.0, 'C');
    cout << "в фаренгейтах: " << t3.tofahrenheit() << "°F" << endl;

    cout << "\nсоздаем с неизвестной шкалой (для теста):" << endl;
    Temperature t4(42.0, 'X');
    cout << "в фаренгейтах: " << t4.tofahrenheit() << "°F" << endl;

    //проверка с разными вариантами написания шкалы
    sep("ПРОВЕРКА РЕГИСТРА");

    Temperature t5(212.0, 'f'); 
    cout << "212°F (маленькая f) в цельсиях: " << t5.getcelsius() << "°C" << endl;

    Temperature t6(273.15, 'k'); 
    cout << "273.15K (маленькая k) в цельсиях: " << t6.getcelsius() << "°C" << endl;

    //массив температур
    sep("МАССИВ ТЕМПЕРАТУР");

    Temperature temps[] = {
        Temperature(25.0),           //цельсии
        Temperature(98.6, 'F'),       //фаренгейты
        Temperature(300.0, 'K'),      //кельвины
        Temperature(-40.0, 'F')     
    };

    cout << "\nвывод массива:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "temps[" << i << "]: ";
        temps[i].show();
        cout << "   в фаренгейтах: " << temps[i].tofahrenheit() << "°F" << endl;
    }

    sep("КОНЕЦ");
    cout << "объекты будут уничтожаться..." << endl;

    return 0;
}
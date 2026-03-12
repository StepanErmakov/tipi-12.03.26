#include <iostream>
#include <string>
#include <clocale>
using namespace std; 

class Logger {
private:
    string logfile;         //имя файла
    int verbositylevel;     //уровень детализации 1-3
    bool isinitialized;     //флаг инициализации

public:
    //главный конструктор с тремя параметрами
    Logger(const string& file, int level, bool init)
        : logfile(file), verbositylevel(level), isinitialized(init) {
        cout << ">> конструктор с 3 параметрами" << endl;
        cout << "   логгер настроен: файл [" << logfile << "], уровень " << verbositylevel;
        cout << ", инициализация: " << (isinitialized ? "да" : "нет") << endl;
    }

    //конструктор с двумя параметрами 
    Logger(const string& file, int level)
        : Logger(file, level, true) { //инициализируем
        cout << ">> конструктор с 2 параметрами (делегирует 3-х параметрическому)" << endl;
    }

    //конструктор с одним параметром
    Logger(const string& file)
        : Logger(file, 1) {
        cout << ">> конструктор с 1 параметром (делегирует 2-х параметрическому)" << endl;
    }

    //конструктор по умолчанию
    Logger()
        : Logger("log.txt") { //файk
        cout << ">> конструктор по умолчанию (делегирует 1-параметрическому)" << endl;
    }

    //деструктор
    ~Logger() {
        cout << ">> деструктор для логгера [файл: " << logfile << "]" << endl;
    }

    //метод для вывода инфы
    void showinfo() const {
        cout << "логгер: файл=\"" << logfile << "\", уровень=" << verbositylevel;
        cout << ", инициализирован=" << (isinitialized ? "да" : "нет") << endl;
    }

    //метод для проверки инициализации
    bool checkinit() const {
        return isinitialized;
    }

    //метод для получения уровня
    int getlevel() const {
        return verbositylevel;
    }
};

//маленькая функция для вывода
void printline(const string& text) {
    cout << "\n--- " << text << " ---" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== демонстрация делегирования конструкторов ===" << endl;

    printline("создаем логгер с 3 параметрами");
    Logger logger1("app.log", 3, true);
    logger1.showinfo();

    printline("создаем логгер с 2 параметрами (файл и уровень)");
    Logger logger2("system.log", 2);
    logger2.showinfo();

    printline("создаем логгер с 1 параметром (только файл)");
    Logger logger3("debug.log");
    logger3.showinfo();

    printline("создаем логгер по умолчанию (без параметров)");
    Logger logger4;
    logger4.showinfo();

    printline("проверка что все работает");

    cout << "уровень logger1: " << logger1.getlevel() << endl;
    cout << "logger2 инициализирован? " << (logger2.checkinit() ? "да" : "нет") << endl;
    cout << "файл logger3: ну хз как получить прямой доступ, но через шоуинфо видно" << endl;

    printline("создаем массив логгеров (без избыточной памяти)");

    Logger loggers[] = {
        Logger("first.log", 3, true),
        Logger("second.log", 2),
        Logger("third.log"),
        Logger()
    };

    cout << "\nвывод массива логгеров:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "логгер[" << i << "]: ";
        loggers[i].showinfo();
    }

    printline("завершение программы");
    cout << "сейчас все объекты начнут уничтожаться (сначала массив, потом отдельные)" << endl;

    return 0;
}
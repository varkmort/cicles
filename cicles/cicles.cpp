#include <iostream>
#include <Windows.h>
#include <random>
#include <chrono>


/*
    Игра угадай число
    программа загадывает число в диапазоне от 10 до 999
    пользователь должен его угадать
    если пользователь вёл число и оно равно загаданному - 
    он победил
    если пользователь не угадал то программа дожна сообщить 
    либо наскольго горячё-холодно было в плане угадывания
    либо больше или меньше попытка чем загаданное число

    в конце работы нужно сообщить сколько времени 
    ушло на угадывание и сколько было попыток
*/

/*
    Вывести все целые числа от значения A до значения B
    значения вводит пользователь
*/

int main()
{
    using namespace std::chrono;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a{};
    int b{};
    auto timeStart = system_clock::now();
    std::cout << "Введите первое число";
    std::cin >> a;
    std::cout << "Введите второе число";
    std::cin >> b;
    auto timeEnd = system_clock::now();
    int secondsCount = 
        duration_cast<seconds>(timeEnd - timeStart).count();

    //если пользователь введёт второе число меньше чем первое
    // их лучше поменять местами

    // while example
    int i = a;
    while (i <= b) {
        std::cout << i << ' ';
        i += 1;
    }
    std::cout << '\n';

    //do-while example
    i = a;
    do {
        std::cout << i << ' ';
        i += 1;
    } while (i <= b);
    std::cout << '\n';

    // for example
    for (int i = a; i <= b; i += 1) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    // задача
    //  вместо чисел введённого пользователем 
    //  числового ряда, вывести случайные 
    //  двузначные числа
    
    //шаг первый создадим генератор случайных чисел
    std::random_device rd;// создали генератор энтропии
    std::mt19937 gen(rd()); // создали генератор 
                            // псевдослучайных чисел
    std::uniform_int_distribution<int> rNum(10, 99);
    // создали поставщика целых чисел для типа int
    // при создании передали граничные значения
    for (int i = a; i <= b; i += 1) {
        std::cout << rNum(gen) << ' ';
    }
    std::cout << '\n';
}

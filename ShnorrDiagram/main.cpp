#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <windows.h>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "\tСоздание подписи\n";
    cout << "Шаг 1: выбор простого числа p и генератора g\n";
    int p = 2147483647;
    cout << "Простое число p = " << p;
    int g = 2;
    cout << "\nГенератор g = " << g;
    cout << "\nШаг 2: выбор случайного числа k\n";
    int k = rand() % (p - 1) + 1;
    cout << "Случайное число k из интервала [1, p-1]: " << k;
    long long R = (long long)pow(g, k) % p;
    cout << "\nШаг 3: вычисление R = g^k mod p\n";
    cout << "Значение R = " << R;
    std::string m = "Hello, World!"; // сообщение для подписи
    cout << "\nШаг 4: вычисление хеш-значения h от сообщения m: " << m;
    std::hash<std::string> hash_fn;
    size_t h = hash_fn(m);
    cout << "\nХеш-значение h: " << h;
    cout << "\nШаг 5: вычисление e = h(R  m), где  обозначает конкатенацию\n";
    std::string R_str = std::to_string(R);
    std::string e_str = R_str + m;
    size_t e = hash_fn(e_str);
    cout << "e: " << e;
    cout << "\nШаг 6: вычисление s = k - xe mod (p-1), где x - секретный ключ отправителя\n";
    int x = 12345;
    cout << "Секретный ключ отправителя: " << x;
    int s = (k - e) % (p - 1);
    cout << "\ns: " << s;
    std::pair<long long, int>signature = std::make_pair(R, s);
    cout << "\nШаг 7: представление цифровой подписи в виде пары (R, s)\n";
    cout << "std::make_pair(R, s)\n";
    cout << "\n\tПроверка подписи\n";
    cout << "Шаг 1: вычисление хеш - значения h от сообщения m\n";
    cout << h;
    cout << "\nШаг 2: вычисление v = g^s y^e mod p, где y - открытый ключ отправителя\n";
    int y = 123456;
    cout << "Открытый ключ отправителя: " << y;
    long long v = (long long)(pow(g, s) * pow(y, e)) % p;
    cout << "\nv: " << v;
    cout << "\nШаг 3: Cравнение R и v\n";
    if (R == v) {
        cout << "R == v\n";
        std::cout << "Подпись действительна" << std::endl;
    }
    else {
        cout << "R != v\n";
        std::cout << "Подпись недействительна" << std::endl;
    }
    return 0;
}
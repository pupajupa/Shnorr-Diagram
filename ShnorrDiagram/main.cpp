#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <windows.h>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "\t�������� �������\n";
    cout << "��� 1: ����� �������� ����� p � ���������� g\n";
    int p = 2147483647;
    cout << "������� ����� p = " << p;
    int g = 2;
    cout << "\n��������� g = " << g;
    cout << "\n��� 2: ����� ���������� ����� k\n";
    int k = rand() % (p - 1) + 1;
    cout << "��������� ����� k �� ��������� [1, p-1]: " << k;
    long long R = (long long)pow(g, k) % p;
    cout << "\n��� 3: ���������� R = g^k mod p\n";
    cout << "�������� R = " << R;
    std::string m = "Hello, World!"; // ��������� ��� �������
    cout << "\n��� 4: ���������� ���-�������� h �� ��������� m: " << m;
    std::hash<std::string> hash_fn;
    size_t h = hash_fn(m);
    cout << "\n���-�������� h: " << h;
    cout << "\n��� 5: ���������� e = h(R  m), ���  ���������� ������������\n";
    std::string R_str = std::to_string(R);
    std::string e_str = R_str + m;
    size_t e = hash_fn(e_str);
    cout << "e: " << e;
    cout << "\n��� 6: ���������� s = k - xe mod (p-1), ��� x - ��������� ���� �����������\n";
    int x = 12345;
    cout << "��������� ���� �����������: " << x;
    int s = (k - e) % (p - 1);
    cout << "\ns: " << s;
    std::pair<long long, int>signature = std::make_pair(R, s);
    cout << "\n��� 7: ������������� �������� ������� � ���� ���� (R, s)\n";
    cout << "std::make_pair(R, s)\n";
    cout << "\n\t�������� �������\n";
    cout << "��� 1: ���������� ��� - �������� h �� ��������� m\n";
    cout << h;
    cout << "\n��� 2: ���������� v = g^s y^e mod p, ��� y - �������� ���� �����������\n";
    int y = 123456;
    cout << "�������� ���� �����������: " << y;
    long long v = (long long)(pow(g, s) * pow(y, e)) % p;
    cout << "\nv: " << v;
    cout << "\n��� 3: C�������� R � v\n";
    if (R == v) {
        cout << "R == v\n";
        std::cout << "������� �������������" << std::endl;
    }
    else {
        cout << "R != v\n";
        std::cout << "������� ���������������" << std::endl;
    }
    return 0;
}
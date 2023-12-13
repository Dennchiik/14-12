#include <iostream>

class Drobi {
private:
    int numer;
    int denom;

public:
    Drobi(int n = 0, int d = 1) : numer(n), denom(d) {}

    void Input() {
        std::cout << "Введите числитель: ";
        std::cin >> numer;
        std::cout << "Введите знаменатель: ";
        std::cin >> denom;
        if (denom == 0) {
            std::cout << "Знаменатель не может быть равен нулю. Устанавливаю знаменатель равным 1." << std::endl;
            denom = 1;
        }
    }

    void Sum(const Drobi& x) {
        numer = numer * x.denom + x.numer * denom;
        denom = denom * x.denom;
        Simplify();
    }

    void Subtract(const Drobi& x) {
        numer = numer * x.denom - x.numer * denom;
        denom = denom * x.denom;
        Simplify();
    }

    void Multiply(const Drobi& x) {
        numer *= x.numer;
        denom *= x.denom;
        Simplify();
    }

    void Divide(const Drobi& x) {
        if (x.numer != 0) {
            numer *= x.denom;
            denom *= x.numer;
            Simplify();
        }
        else {
            std::cout << "Деление на ноль. Операция невозможна." << std::endl;
        }
    }

    void Display() const {
        std::cout << numer << "/" << denom << std::endl;
    }

private:
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    void Simplify() {
        int gcd = GCD(numer, denom);
        numer /= gcd;
        denom /= gcd;
    }
};

int main() {
    Drobi fraction1, fraction2;

    std::cout << "Введите данные для первой дроби:\n";
    fraction1.Input();
    std::cout << "Первая дробь: ";
    fraction1.Display();

    std::cout << "\nВведите данные для второй дроби:\n";
    fraction2.Input();
    std::cout << "Вторая дробь: ";
    fraction2.Display();

    std::cout << "\nРезультаты операций:\n";

    Drobi result;

    result = fraction1;
    result.Sum(fraction2);
    std::cout << "Сумма: ";
    result.Display();

    result = fraction1;
    result.Subtract(fraction2);
    std::cout << "Разность: ";
    result.Display();

    result = fraction1;
    result.Multiply(fraction2);
    std::cout << "Произведение: ";
    result.Display();

    result = fraction1;
    result.Divide(fraction2);
    std::cout << "Частное: ";
    result.Display();

    return 0;
}

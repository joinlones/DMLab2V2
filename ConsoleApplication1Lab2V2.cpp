#include <iostream>
#include <vector>

// Функция для вычисления логического выражения
bool expression(bool a, bool b, bool c, bool d, bool e) {
    return (a && b && !c) || (!d && e);
}

// Вывод таблицы истинности
void print_truth_table() {
    std::cout << "a b c d e | f\n";
    for (int i = 0; i < 32; ++i) {
        bool a = (i & 16) >> 4;
        bool b = (i & 8) >> 3;
        bool c = (i & 4) >> 2;
        bool d = (i & 2) >> 1;
        bool e = (i & 1) >> 0;
        bool result = expression(a, b, c, d, e);
        std::cout << a << " " << b << " " << c << " " << d << " " << e << " | " << result << "\n";
    }
}

// Построение СДНФ
void print_SDNF() {
    std::vector<std::string> terms;
    for (int i = 0; i < 32; ++i) {
        bool a = (i & 16) >> 4;
        bool b = (i & 8) >> 3;
        bool c = (i & 4) >> 2;
        bool d = (i & 2) >> 1;
        bool e = (i & 1) >> 0;
        if (expression(a, b, c, d, e)) {
            std::string term;
            term += (a ? "a" : "!a");
            term += " & ";
            term += (b ? "b" : "!b");
            term += " & ";
            term += (c ? "c" : "!c");
            term += " & ";
            term += (d ? "d" : "!d");
            term += " & ";
            term += (e ? "e" : "!e");
            terms.push_back(term);
        }
    }
    std::cout << "СДНФ: ";
    for (size_t i = 0; i < terms.size(); ++i) {
        std::cout << (i == 0 ? "" : " | ") << "(" << terms[i] << ")";
    }
    std::cout << "\n";
}

// Построение СКНФ
void print_SKNF() {
    std::vector<std::string> terms;
    for (int i = 0; i < 32; ++i) {
        bool a = (i & 16) >> 4;
        bool b = (i & 8) >> 3;
        bool c = (i & 4) >> 2;
        bool d = (i & 2) >> 1;
        bool e = (i & 1) >> 0;
        if (!expression(a, b, c, d, e)) {
            std::string term;
            term += (a ? "!a" : "a");
            term += " | ";
            term += (b ? "!b" : "b");
            term += " | ";
            term += (c ? "!c" : "c");
            term += " | ";
            term += (d ? "!d" : "d");
            term += " | ";
            term += (e ? "!e" : "e");
            terms.push_back(term);
        }
    }
    std::cout << "СКНФ: ";
    for (size_t i = 0; i < terms.size(); ++i) {
        std::cout << (i == 0 ? "" : " & ") << "(" << terms[i] << ")";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Таблица истинности:\n";
    print_truth_table();

    std::cout << "\n";

    print_SDNF();
    std::cout << "\n";

    print_SKNF();

    return 0;
}
//
// Created by Mikhail on 19.03.2025.
//

#include <iostream>
#include <string>

class Stroka {
private:
    std::string text;

public:
    Stroka(const std::string& t = "") : text(t) {}

    // Перегрузка оператора вывода (<<)
    friend std::ostream& operator<<(std::ostream& os, const Stroka& s) {
        os << s.text;
        return os;
    }

    // Перегрузка оператора ввода (>>)
    friend std::istream& operator>>(std::istream& is, Stroka& s) {
        is >> s.text;
        return is;
    }

    void setText(const std::string& t) {
        text = t;
    }

    std::string getText() const {
        return text;
    }
};

int main() {
    Stroka s;
    std::cout << "Enter text: ";
    std::cin >> s;
    std::cout << "You entered: " << s << std::endl;
    return 0;
}


//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <stack>
using namespace std;

// Класс для представления поезда
class TrainCar {
public:
    int number;

    TrainCar(int num) : number(num) {}

    // Операторы сравнения для сортировки
    bool operator>(const TrainCar& other) const {
        return number > other.number;
    }

    bool operator<(const TrainCar& other) const {
        return number < other.number;
    }

    friend ostream& operator<<(ostream& os, const TrainCar& car) {
        os << "Car " << car.number;
        return os;
    }
};

template <class T>
class TStack {
private:
    stack<T> stk;
public:
    void push(const T& item) {
        stk.push(item);
    }

    T pop() {
        T top = stk.top();  // Получаем верхний элемент
        stk.pop();           // Удаляем его из стека
        return top;          // Возвращаем его
    }

    bool empty() const {
        return stk.empty();
    }

    T top() const {
        return stk.top();
    }
};

void sortTrain(TStack<TrainCar>& stack) {
    TStack<TrainCar> tempStack;

    // Пример сортировки поездов
    while (!stack.empty()) {
        TrainCar topCar = stack.pop();
        while (!tempStack.empty() && tempStack.top() > topCar) {
            stack.push(tempStack.pop());
        }
        tempStack.push(topCar);
    }

    // Переносим элементы обратно в основной стек
    while (!tempStack.empty()) {
        stack.push(tempStack.pop());
    }
}

int main() {
    TStack<TrainCar> trainStack;

    // Добавляем вагоны
    trainStack.push(TrainCar(5));
    trainStack.push(TrainCar(1));
    trainStack.push(TrainCar(3));
    trainStack.push(TrainCar(2));
    trainStack.push(TrainCar(4));

    cout << "Before sorting:" << endl;
    TStack<TrainCar> tempStack = trainStack;
    while (!tempStack.empty()) {
        cout << tempStack.pop() << endl;
    }

    // Сортировка
    sortTrain(trainStack);

    cout << "After sorting:" << endl;
    while (!trainStack.empty()) {
        cout << trainStack.pop() << endl;
    }

    return 0;
}

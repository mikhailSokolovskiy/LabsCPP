//
// Created by Mikhail on 19.03.2025.
//
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;

    Node(T d) : data(d), next(nullptr) {}
};

template <class T>
class SinglyLinkedList {
private:
    Node<T>* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Добавление элемента в список
    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Удаление элемента из списка по номеру автобуса
    bool remove(int busNumber) {
        Node<T>* temp = head;
        Node<T>* prev = nullptr;

        while (temp) {
            if (temp->data.busNumber == busNumber) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    // Вывод всех элементов списка
    void print() const {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Проверка, пуст ли список
    bool isEmpty() const {
        return head == nullptr;
    }
};

// Структура для хранения информации о автобусе
struct Bus {
    int busNumber;
    string driverName;
    int routeNumber;

    Bus(int busNum, const string& driver, int route)
        : busNumber(busNum), driverName(driver), routeNumber(route) {}

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Bus Number: " << bus.busNumber << ", Driver: " << bus.driverName
           << ", Route: " << bus.routeNumber;
        return os;
    }
};

int main() {
    SinglyLinkedList<Bus> busPark;
    SinglyLinkedList<Bus> routePark;

    // Добавление автобусов в парк
    busPark.add(Bus(1, "Ivanov I.I.", 101));
    busPark.add(Bus(2, "Petrov P.P.", 102));
    busPark.add(Bus(3, "Sidorov S.S.", 103));

    cout << "Buses in the bus park:\n";
    busPark.print();

    // Ввод данных о выезде автобуса
    int busNumber;
    cout << "\nEnter the bus number leaving the park: ";
    cin >> busNumber;

    // Удаление из парка и добавление в маршрут
    if (busPark.remove(busNumber)) {
        cout << "Bus " << busNumber << " has left the park.\n";
        routePark.add(Bus(busNumber, "", 0));  // Вставляем автобус без водителя и маршрута в маршрут
    } else {
        cout << "Bus " << busNumber << " not found in the park.\n";
    }

    // Вывод информации о автобусах в парке
    cout << "\nBuses in the bus park after departure:\n";
    busPark.print();

    // Вывод информации о автобусах на маршруте
    cout << "\nBuses on the route:\n";
    routePark.print();

    // Ввод данных о возвращении автобуса в парк
    cout << "\nEnter the bus number returning to the park: ";
    cin >> busNumber;

    // Удаление из маршрута и добавление обратно в парк
    if (routePark.remove(busNumber)) {
        cout << "Bus " << busNumber << " has returned to the park.\n";
        busPark.add(Bus(busNumber, "", 0));  // Вставляем автобус без водителя и маршрута обратно в парк
    } else {
        cout << "Bus " << busNumber << " not found on the route.\n";
    }

    // Вывод информации о автобусах в парке
    cout << "\nBuses in the bus park after return:\n";
    busPark.print();

    return 0;
}

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "chat.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

//Добавить наблюдателя на подписку
void Chat::attach(IObserver* observer) {

} 

//Исключить наблюдателя из подписку
void Chat::dettach(IObserver* observer) {

}

//Разослать информацию
void Chat::notify() {
}

//Получить общее количество сообщений
unsigned int Chat::getAmount() const {
    return 0;
}

//Показать первое меню
char Chat::showHelloMenu() {
   SetConsoleTextAttribute(hConsole_, 224);
    char choice = '0';
    while (true) {
        cout << "Добрый день! Добро пожаловать в чат. Что будем делать?" << endl;
        cout << "1. Войти" << endl;
        cout << "2. Регистрация" << endl;
        cout << "q - Выход" << endl;
        cout << "Введите символ: ";     
        cin >> choice;
        if (choice == '1' || choice == '2' || choice == 'q') {
            break;
        }
        else {
            system("cls");
            cout << "Команды " << choice << " не знаю!!!" << endl;
            system("pause");
            system("cls");
        }
    }
   SetConsoleTextAttribute(hConsole_, 15);
    system("cls");
    return choice;
}

//Покащать меню регистрации
void Chat::showRegistrationMenu() {
    string tname;
    string tpassword;
    string tlogin;
    while (true) {
        cout << "Введите регистрационные данные" << endl;
        cout << "Имя: ";
        cin >> tname;
        cout << "Логин: ";
        cin >> tlogin;
        cout << "Пароль: ";
        cin >> tpassword;
        break;
    }

    system("cls");
    cout << "Вы зарегестрированы! " << endl;
    cout << tname << " " << tlogin << " " << tpassword << endl;
    system("pause");
    system("cls");
}

//Получить общее количество личных сообщений для пользователя
unsigned int Chat::getAmountSelfMessage() const {
    return 0;
}
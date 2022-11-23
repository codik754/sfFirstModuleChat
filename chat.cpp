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

//Исключить наблюдателя из подписки
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
    SetConsoleTextAttribute(hConsole_, 10);
    char choice = '0';
    while (true) {
        cout << "Добрый день! Добро пожаловать в чат. Что будем делать?" << endl;
        SetConsoleTextAttribute(hConsole_, 176);
        cout << "1. Войти" << endl;
        cout << "2. Регистрация" << endl;
        cout << "q - Выход" << endl;
        SetConsoleTextAttribute(hConsole_, 15);
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
/*#include <conio.h>
#include <string>
#include <iostream>
#include <vector>

void sign_in()
{
    std::string       login;
    std::vector<char> password;

    char c;

    std::cout << "Enter login: ";
    std::cin >> login;
    std::cout << "Enter password: ";
    while ((c = _getch()) != '\r')
    {
        password.push_back(c);
        _putch('*');
    }

    std::cout << std::endl << login << " : ";

    for (std::size_t i = 0; i < password.size(); ++i)
        std::cout << password[i];
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    sign_in();

    return 0;
}
*/
//Показать меню регистрации
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
    return amount_;
}

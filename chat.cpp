// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "chat.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

//�������� ����������� �� ��������
void Chat::attach(IObserver* observer) {

}

//��������� ����������� �� ��������
void Chat::dettach(IObserver* observer) {

}

//��������� ����������
void Chat::notify() {
}

//�������� ����� ���������� ���������
unsigned int Chat::getAmount() const {
    return 0;
}

//�������� ������ ����
char Chat::showHelloMenu() {
    SetConsoleTextAttribute(hConsole_, 10);
    char choice = '0';
    while (true) {
        cout << "������ ����! ����� ���������� � ���. ��� ����� ������?" << endl;
        SetConsoleTextAttribute(hConsole_, 176);
        cout << "1. �����" << endl;
        cout << "2. �����������" << endl;
        cout << "q - �����" << endl;
        SetConsoleTextAttribute(hConsole_, 15);
        cout << "������� ������: ";
        cin >> choice;
        if (choice == '1' || choice == '2' || choice == 'q') {
            break;
        }
        else {
            system("cls");
            cout << "������� " << choice << " �� ����!!!" << endl;
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
//�������� ���� �����������
void Chat::showRegistrationMenu() {
    string tname;
    string tpassword;
    string tlogin;
    while (true) {
        cout << "������� ��������������� ������" << endl;
        cout << "���: ";
        cin >> tname;
        cout << "�����: ";
        cin >> tlogin;
        cout << "������: ";
        cin >> tpassword;
        break;
    }

    system("cls");
    cout << "�� ����������������! " << endl;
    cout << tname << " " << tlogin << " " << tpassword << endl;
    system("pause");
    system("cls");
}

//�������� ����� ���������� ������ ��������� ��� ������������
unsigned int Chat::getAmountSelfMessage() const {
    return amount_;
}

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <memory>
#include "chat.h"
#include "user.h"

using std::cout;
using std::endl;
using std::cin;

//В этой функции реализуется основной код
void clientCode() {
}


int main() {
	setlocale(LC_ALL, "");

	Chat chat;
	char choice = '0';//Функция для выбора

	while (choice != 'q') {
		if (choice == '0') {
			choice = chat.showHelloMenu();
		}
		else if(choice == '1') {
			chat.showLogIn();
			choice = '0';
		}
		else if (choice == '2') {
			chat.showRegistrationMenu();
			choice = '0';
		}
		
		if (choice == 'q') {
			chat.setColorToConsole(12);
			cout << "До встречи!!!" << endl;
			chat.setColorToConsole(15);
		}

	}

	return 0;
}
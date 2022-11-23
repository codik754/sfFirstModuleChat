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
	int menu = 0;//какое меню печатать
	char choice = '0';

	while (choice != 'q') {
		if (choice == '0') {
			choice = chat.showHelloMenu();
		}
		else if (choice == '1') {
		
		}
		else if (choice == '2') {
			chat.showRegistrationMenu();
			choice = '0';
		}
	}

		//system("pause");
		//system("cls");
	/*
			int operation;
			char userdata;
			std::cin >> operation;


			switch (operation) {

			case 1:
				std::cout << "Enter your login" << std::endl;
				std::cin >> userdata;
				break;

			case 2:

				std::cout << "Enter your password" << std::endl;
				std::cin >> userdata;
				break;

			case 0:
				std::cout << "Bye!!!" << std::endl;
				break;

			default:
				std::cout << "I don't know!" << std::endl;
			}

			*/

	return 0;
}
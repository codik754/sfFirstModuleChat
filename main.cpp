#include <iostream>
#include "User.h"

using namespace std;

int main() {
/*	std::cout << "Welcome!" << std::endl << "Wish you enter?" << std::endl
		<< "Enter (1) to enter your login and password" << std::endl
		<< "Or you need to checkin. Enter (2)" << std::endl<<"(0) for Exit"<<std::endl;*/
	
	
		User A("Vasya", "Tatyana", "Text message");
		cout << A.getLogin() << endl;
		cout << A.getPassword() << endl;
		cout << A.getName() << endl;

		A.setName("New name");
		A.setPassword("New password");

		cout << A.getLogin() << endl;
		cout << A.getPassword() << endl;
		cout << A.getName() << endl;
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
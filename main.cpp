//Файл main.cpp
#include <iostream>
#include "message.h"

#include "datetime.h"

using std::cout;
using std::endl;

int main() {
	Message A("Ivan", "Tatyana", "Text message");
	cout << A.getDatetime() << endl;
	Datetime D;
	cout << D.getStr() << endl;
	return 0;
}
#pragma once
#include "ipublisher.h"
#include <vector>
#include <list>
#include <memory>
#include "user.h"
#include "message.h"
#include <windows.h>

using std::vector;
using std::list;

class Chat : public IPublisher{
	vector<User> users_;   //вектор пользователей зарегестрировавшихся в системе
	vector<Message> message_;//вектор сообщений
	list<IObserver*> subscribers_; //список подписчиков
	unsigned int amount_;//общее количество сообщений
	HANDLE hConsole_;//поле нужно для работы с цветом в консоле Windows

public:
	//Конструктор по умолчанию
	Chat() : users_(), message_(), subscribers_(), amount_(0), hConsole_(GetStdHandle(STD_OUTPUT_HANDLE)) {}

	virtual ~Chat() = default;//деструктор класса

	void attach(IObserver* observer) override; //добавить наблюдателя на подписку
	void dettach(IObserver* observer) override; //исключить наблюдателя из подписку
	void notify() override; //разослать информацию

	unsigned int getAmount() const;//получить общее количество сообщений

	unsigned int getAmountSelfMessage() const;//получить общее количество личных сообщений для пользователя

	char showHelloMenu();//показать первое меню
	
	void showRegistrationMenu();//покащать меню регистрации

	

};


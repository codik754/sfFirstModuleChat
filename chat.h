//Файл chat.h
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
using std::unique_ptr;

//Класс для чата
class Chat : public IPublisher {
	vector<User> users_;   //вектор пользователей зарегестрировавшихся в системе
	vector<Message> message_;//вектор сообщений
	list<IObserver*> subscribers_; //список подписчиков
	unsigned int amountAll_;//общее количество общих сообщений
	HANDLE hConsole_;//поле нужно для работы с цветом в консоле Windows
	unique_ptr<User*> currentUser;//указатель на текущего пользователя

public:
	//Конструктор по умолчанию
	Chat() : users_(), message_(), subscribers_(), amountAll_(0), hConsole_(GetStdHandle(STD_OUTPUT_HANDLE)), currentUser(nullptr) {
		//Создаем пользователя и добавляем в вектор
		users_.reserve(100);//резервируем место для вектора
		users_.emplace_back(User("admin", "a123", "ADMIN", std::make_unique<IPublisher*>(this)));
	}

	virtual ~Chat() = default;//деструктор класса

	void attach(IObserver* observer) override; //добавить наблюдателя на подписку
	void dettach(IObserver* observer) override; //исключить наблюдателя из подписки
	void notifyAboutAll() override; //разослать информацию про общий чат
	void notifyAboutSelf(const string& login) override; //проинформировать про личное сообщение

	unsigned int getAmountSelfMessage(const string &login) const;//получить общее количество личных сообщений для пользователя

	char showHelloMenu();//показать первое меню

	void showRegistrationMenu();//показать меню регистрации
	void showLogIn();//показать меню для входа
	void showChatMenu();//показать меню общего чата
	void showWriteMessageMenu();//показать меню для написания сообщений

	void setColorToConsole(WORD n);//установить цвет в консоле

	unique_ptr<User*> getUser(const string &login, const string &password);//получить пользователя с определенным логином и паролем

	bool checkLogin(const string& login);//проверка существует ли пользователь с таким логином

	void addMessage(const string& from, const string &to, const string& text);//добавить сообщение
};


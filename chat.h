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

class Chat : public IPublisher {
	vector<User> users_;   //вектор пользователей зарегестрировавшихся в системе
	vector<Message> message_;//вектор сообщений
	list<IObserver*> subscribers_; //список подписчиков
	unsigned int amountAll_;//общее количество общих сообщений
	HANDLE hConsole_;//поле нужно для работы с цветом в консоле Windows
	User* currentUser;//указатель на текущего пользователя

public:
	//Конструктор по умолчанию
	Chat() : users_(), message_(), subscribers_(), amountAll_(0), hConsole_(GetStdHandle(STD_OUTPUT_HANDLE)), currentUser(nullptr) {
		//Создаем пользователя и добавляем в вектор
		users_.reserve(100);
		users_.emplace_back(User("admin", "a123", "ADMIN", this));

		/*

		addMessage("codik", "all", "Text message1");
		addMessage("LvUser", "all", "Text message2");
		addMessage("User1", "all", "Text message2");
		addMessage("User2", "all", "Text message2");
		addMessage("User3", "all", "Text message2");
		addMessage("User4", "all", "Text message2");
		addMessage("User5", "all", "Text message2");
		addMessage("User6", "all", "Text message2");
		addMessage("User7", "all", "Text message2");
		addMessage("User8", "all", "Text message2");
		addMessage("User9", "all", "Text message2");
		addMessage("User10", "all", "Text message2");
		addMessage("User11", "all", "Text message2");
		addMessage("User12", "all", "Text message2");
		addMessage("User13", "all", "Text message2");
		addMessage("User14", "all", "Text message2");
		addMessage("User15", "all", "Text message2");
		addMessage("User16", "all", "Text message2");
		addMessage("User17", "all", "Text message2");
		addMessage("User18", "all", "Text message2");
		addMessage("User19", "all", "Text message2");
		addMessage("User20", "all", "Text message2");

		addMessage("codik", "admin", "Text message1");
		addMessage("codik1", "admin", "Text message1");
		addMessage("codik2", "admin", "Text message1");
		addMessage("codik3", "admin", "Text message1");
		addMessage("codik4", "admin", "Text message1");
		addMessage("codik5", "admin", "Text message1");
		addMessage("codik6", "admin", "Text message1");
		addMessage("codik7", "admin", "Text message1");
		addMessage("codik8", "admin", "Text message1");
		addMessage("codik9", "admin", "Text message1");
		addMessage("codik10", "admin", "Text message1");
		addMessage("codik11", "admin", "Text message1");
		addMessage("codik12", "admin", "Text message1");
		addMessage("codik13", "admin", "Text message1");
		addMessage("codik14", "admin", "Text message1");
		addMessage("codik15", "admin", "Text message1");
		addMessage("codik16", "admin", "Text message1");
		addMessage("codik17", "admin", "Text message1");
		addMessage("codik18", "admin", "Text message1");
		addMessage("codik19", "admin", "Text message1");
		addMessage("codik20", "admin", "Text message1");
		*/
		
	}

	virtual ~Chat() = default;//деструктор класса

	void attach(IObserver* observer) override; //добавить наблюдателя на подписку
	void dettach(IObserver* observer) override; //исключить наблюдателя из подписки
	void notifyAboutAll() override; //разослать информацию про общий чат
	void notifyAboutSelf(const string& login) override; //проинформировать про личное сообщение


	unsigned int getAmountAll() const;//получить общее количество сообщений

	unsigned int getAmountSelfMessage(const string &login) const;//получить общее количество личных сообщений для пользователя

	char showHelloMenu();//показать первое меню

	void showRegistrationMenu();//показать меню регистрации
	void showLogIn();//показать меню для входа
	void showChatMenu();//показать меню общего чата
	void showWriteMessageMenu();//показать меню для написания сообщений

	void setColorToConsole(WORD n);//установить цвет в консоле

	User* getUser(const string &login, const string &password);//получить пользователя с определенным логином и паролем

	bool checkLogin(const string& login);//проверка существует ли польозователь с таким логином

	void addMessage(const string& from, const string &to, const string& text);//добавить сообщение
};


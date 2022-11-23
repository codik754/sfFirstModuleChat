#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "iobserver.h"
#include "ipublisher.h"

using std::shared_ptr;

class User : public IObserver {

	const std::string login_;//поле для логина
	std::string password_;//поле для пароля
	std::string name_;//поле для имени
	unsigned int amountSelfMessags_; //количество личных сообщений
	unsigned int newSelfMessages_;  //количесвто новых личных сообщений
	bool isSubribes_; //пользователь подписан на оповещения
	shared_ptr<IPublisher> publisher_; //указатель на издателя


public:
	//Параметризированный конструктор
	User(const std::string& login, const std::string& password, const std::string& name, shared_ptr<IPublisher> publisher)
		: login_(login), password_(password), name_(name), amountSelfMessags_(0), newSelfMessages_(0), isSubribes_(true), publisher_(publisher) {}

	const std::string& getLogin() const;//получить логин
	const std::string& getName() const;//получить имя
	const std::string& getPassword() const;//получить пароль

	void setPassword(const std::string& password);//установить пароль
	void setName(const std::string& name);//установить имя

	virtual ~User() = default;//деструктор класса

	void updateInformation() override;//обновить информацию полученную от Издателя

};



// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "user.h"

//Получить логин
const std::string& User::getLogin() const {
	return login_;
}

//Получить имя
const std::string& User::getName() const {
	return name_;
}

//Получить пароль
const std::string& User::getPassword() const {
	return password_;
}

//Установить пароль
void User::setPassword(const std::string& password) {
	password_ = password;
}

//Установить имя
void User::setName(const std::string& name) {
	name_ = name;
}

//Обновить информацию полученную от Издателя про общий чат
void User::updateInformationAll() {
	++newAllMessages_;
}

//Обновить информацию полученную от Издателя про личные сообщения
void User::updateInformationSelf() {
	//++amountSelfMessages_;
	++newSelfMessages_;
}

//метод для сравнения поля логин с переданным значением
bool User::isThisI(const string& str) {
	if (login_ == str) {
		return true;
	}
	else {
		return false;
	}
}

//Подписаться на уведомления
void User::subscribe() {
	publisher_->attach(this);
	isSubribes_ = true;
}

//Отписаться от уведомления
void User::unscribe() {
	publisher_->dettach(this);
	isSubribes_ = false;
}


//Проверка логина
bool User::checkLogin(const string& login) const {
	if (login_ == login) {
		return true;
	}
	else {
		return false;
	}
}

//Проверка пароля
bool User::checkPassword(const string& password) const {
	if (password_ == password) {
		return true;
	}
	else {
		return false;
	}
}

//Получить статус подписки
bool User::getIsSubscribes() const {
	return isSubribes_;
}

//Получить количество личных сообщений
unsigned int User::getAmountSelfMessages() {
	return amountSelfMessages_;
}

//Получить количество новых непрочитыннах личных сообщений
unsigned int User::getNewSelfMessages() {
	return newSelfMessages_;
} 

//Получить количество новых непрочитанных сообщений в общем чате
unsigned int User::getNewAllMessages() {
	return newAllMessages_;
}

//Сбросить количество непрочитанных сообщений в общем чате в 0
void User::resetNewAllMessages() {
	newAllMessages_ = 0;
}

//Сбросить количество непрочитанных сообщений в личных сообщениях в 0
void User::resetNewSelfMessages() {
	newSelfMessages_ = 0;
}

//Установить значение для amountSelfMessages_
void User::setAmountSelfMessages(unsigned int n) {
	amountSelfMessages_ = n;
}
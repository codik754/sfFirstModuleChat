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

//обновить информацию полученную от Издателя
void User::updateInformation() {

}
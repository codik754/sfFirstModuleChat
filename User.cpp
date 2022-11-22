#include "User.h"

const std::string& User::getLogin() const {
	return login_; 
}

const std::string& User::getName() const { 
	return name_; 
}
const std::string& User::getPassword() const { 
	return password_; 
}

void User::setPassword(const std::string& password) { 
	password_ = password; 
}

void User::setName(const std::string& name) { 
	name_ = name; 
}
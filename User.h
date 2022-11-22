#pragma once
#include<iostream>
#include <string>

class User{

	const std::string login_;
	std::string password_;
	std::string name_;

public:
	User(const std::string& login, const std::string& password, const std::string& name) 
		: login_(login), password_(password), name_(name) {}

	const std::string& getLogin() const;
	const std::string& getName() const;
	const std::string& getPassword() const;

	void setPassword(const std::string& password);
	void setName(const std::string& name);

	
};


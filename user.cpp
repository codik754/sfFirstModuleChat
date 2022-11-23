// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "user.h"

//�������� �����
const std::string& User::getLogin() const {
	return login_;
}

//�������� ���
const std::string& User::getName() const {
	return name_;
}

//�������� ������
const std::string& User::getPassword() const {
	return password_;
}

//���������� ������
void User::setPassword(const std::string& password) {
	password_ = password;
}

//���������� ���
void User::setName(const std::string& name) {
	name_ = name;
}

//�������� ���������� ���������� �� ��������
void User::updateInformation() {

}

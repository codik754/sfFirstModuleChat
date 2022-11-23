#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "iobserver.h"
#include "ipublisher.h"

using std::shared_ptr;

class User : public IObserver {

	const std::string login_;//���� ��� ������
	std::string password_;//���� ��� ������
	std::string name_;//���� ��� �����
	unsigned int amountSelfMessags_; //���������� ������ ���������
	unsigned int newSelfMessages_;  //���������� ����� ������ ���������
	bool isSubribes_; //������������ �������� �� ����������
	shared_ptr<IPublisher> publisher_; //��������� �� ��������


public:
	//������������������� �����������
	User(const std::string& login, const std::string& password, const std::string& name, shared_ptr<IPublisher> publisher)
		: login_(login), password_(password), name_(name), amountSelfMessags_(0), newSelfMessages_(0), isSubribes_(true), publisher_(publisher) {}

	const std::string& getLogin() const;//�������� �����
	const std::string& getName() const;//�������� ���
	const std::string& getPassword() const;//�������� ������

	void setPassword(const std::string& password);//���������� ������
	void setName(const std::string& name);//���������� ���

	virtual ~User() = default;//���������� ������

	void updateInformation() override;//�������� ���������� ���������� �� ��������

};



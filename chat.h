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
	vector<User> users_;   //������ ������������� �������������������� � �������
	vector<Message> message_;//������ ���������
	list<IObserver*> subscribers_; //������ �����������
	unsigned int amount_;//����� ���������� ���������
	HANDLE hConsole_;//���� ����� ��� ������ � ������ � ������� Windows

public:
	//����������� �� ���������
	Chat() : users_(), message_(), subscribers_(), amount_(0), hConsole_(GetStdHandle(STD_OUTPUT_HANDLE)) {}

	virtual ~Chat() = default;//���������� ������

	void attach(IObserver* observer) override; //�������� ����������� �� ��������
	void dettach(IObserver* observer) override; //��������� ����������� �� ��������
	void notify() override; //��������� ����������

	unsigned int getAmount() const;//�������� ����� ���������� ���������

	unsigned int getAmountSelfMessage() const;//�������� ����� ���������� ������ ��������� ��� ������������

	char showHelloMenu();//�������� ������ ����

	void showRegistrationMenu();//�������� ���� �����������



};


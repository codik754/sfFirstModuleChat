//���� message.h
#pragma once
#include <string>
#include "datetime.h"

using std::string;

class Message {
	const string sendedFrom_;//�� ���� ���������� ���������
	const string sendedTo_;  //���� ���������� ���������
	const string text_;	//����� ���������
	const Datetime dateandtime_; //���� �������� ���������
public:
	//����������� �� ���������
	Message();
	//����������� � �����������
	Message(const string& from, const string& to, const string& text);

	//������ �� ���� ���������� ���������
	const string& getSendedFrom() const;
	//������ ���� ���������� ���������
	const string& getSendedTo() const;
	//�������� ����� ���������
	const string& getText() const;
	//�������� ���� � �����
	const string getDatetime() const;
};

//���� datetime.h
#pragma once
#include<windows.h>
#include <string>

using std::string;
class Datetime
{
	int sec_;  //�������
	int min_;  //������
	int hour_; //���
	int day_;  //����
	int month_;//�����
	int year_; //���
public:
	
	//����������� �� ���������
	Datetime();

	//���������� ������� �����
	void setNow();

	//�������� �������
	int getSec() const;
	//�������� ������
	int getMin() const;
	//�������� ����
	int getHour() const;
	//�������� ����
	int getDay() const;
	//�������� �����
	int getMonth() const;
	//�������� ���
	int getYear() const;
	//�������� ���� � ����� � ���� ������
	const string getStr() const;
};


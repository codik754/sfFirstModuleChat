//���� iobserver.h
#pragma once

//��������� ��� �����������
class IObserver {
public:
	virtual ~IObserver() = default; //���������� ������
	virtual void updateInformation() = 0;//�������� ���������� ���������� �� ��������
};

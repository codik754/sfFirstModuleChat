#pragma once
#include "iobserver.h"

//��������� ��� ��������
class IPublisher {
public:
	virtual ~IPublisher() = default; //���������� ������

	virtual void attach(IObserver* observer) = 0; //�������� ����������� �� ��������
	virtual void dettach(IObserver* observer) = 0; //��������� ����������� �� ��������
	virtual void notify() = 0; //��������� ����������
};

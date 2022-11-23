#pragma once
#include "iobserver.h"

//Интерфейс для Издателя
class IPublisher {
public:
	virtual ~IPublisher() = default; //деструктор класса

	virtual void attach(IObserver* observer) = 0; //добавить наблюдателя на подписку
	virtual void dettach(IObserver* observer) = 0; //исключить наблюдателя из подписки
	virtual void notify() = 0; //разослать информацию
};

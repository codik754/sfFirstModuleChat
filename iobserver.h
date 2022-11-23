//Файл iobserver.h
#pragma once

//Интерфейс для Наблюдателя
class IObserver {
public:
	virtual ~IObserver() = default; //деструктор класса
	virtual void updateInformation() = 0;//обновить информацию полученную от Издателя
};
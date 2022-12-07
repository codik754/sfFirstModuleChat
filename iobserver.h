//Файл iobserver.h
#pragma once
#include <string>

using std::string;

//Интерфейс для Наблюдателя
class IObserver {
public:
	virtual ~IObserver() = default; //деструктор класса
	virtual void updateInformationAll() = 0;//обновить информацию полученную от Издателя про общий чат
	virtual void updateInformationSelf() = 0;//обновить информацию полученную от Издателя про личные сообщения
	virtual bool isThisI(const string& str) = 0;//метод для сравнения какого-либо поля с переаднным значением
};

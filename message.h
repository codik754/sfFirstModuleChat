//Файл message.h
#pragma once
#include <string>
#include "datetime.h"

using std::string;

class Message {
	const string sendedFrom_;//от кого отправлено сообщение
	const string sendedTo_;  //кому отправлено сообщение
	const string text_;	//текст сообщения
	const Datetime dateandtime_; //дата отправки сообщения
public:
	//Конструктор по умолчанию
	Message();
	//Конструктор с параметрами
	Message(const string& from, const string& to, const string& text);
	//Конструктор копирования
	Message(const Message& other);
	//Деструктор
	~Message() = default;
	
	//Оператор присваивания
	const Message& operator = (const Message& other);

	//Узнать от кого отправлено сообщение
	const string& getSendedFrom() const;
	//Получить текст сообщения
	const string& getText() const;
	//Получить дату и время
	const string getDatetime() const;
	//Соответсвует ли поле кому отправлено сообщение переданной строке
	bool checkToSendedTo(const string &login) const;
};

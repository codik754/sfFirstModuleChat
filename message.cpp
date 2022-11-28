// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//Файл message.cpp
#include "message.h"

//Конструктор по умолчанию
Message::Message() : sendedFrom_("UNKNOWN"), sendedTo_("UNKNOWN"), text_("UNKNOWN"), dateandtime_() {}

//Конструктор с параметрами
Message::Message(const string& from, const string& to, const string& text) : sendedFrom_(from), sendedTo_(to), text_(text), dateandtime_() {}

//Конструктор копирования
Message::Message(const Message& other) : sendedFrom_(other.sendedFrom_), sendedTo_(other.sendedTo_), text_(other.text_), dateandtime_(other.dateandtime_) {}

//Узнать от кого отправлено сообщение
const string& Message::getSendedFrom() const {
	return sendedFrom_;
}

//Узнать кому отправлено сообщение
const string& Message::getSendedTo() const {
	return sendedTo_;
}

//Получить текст сообщения
const string& Message::getText() const {
	return text_;
}

//Получить дату и время
const string Message::getDatetime() const {
	return dateandtime_.getStrAll();
}

//Соответсвует ли поле кому отправлено сообщение переданной строке
bool Message::checkToSendedTo(const string& login) const {
	if (sendedTo_ == login) {
		return true;
	}
	else {
		return false;
	}
}

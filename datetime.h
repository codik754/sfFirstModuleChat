//Файл datetime.h
#pragma once

#include <string>

using std::string;

class Datetime
{	
	int sec_;  //секунды
	int min_;  //минуты
	int hour_; //час
	int day_;  //день
	int month_;//месяц
	int year_; //год
public:
	//Конструктор по умолчанию
	Datetime();

	//Установить текущие время
	void setNow();

	//Получить секунды
	int getSec() const;
	//Получить минуты
	int getMin() const;
	//Получить часы
	int getHour() const;
	//Получить день
	int getDay() const;
	//Получить месяц
	int getMonth() const;
	//Получить год
	int getYear() const;
	//Получить дату и время в виде строки
	const string getStr() const;
};


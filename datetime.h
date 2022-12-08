﻿//Файл datetime.h
#pragma once
#include<windows.h>
#include <string>

using std::string;

//Класс для даты и времени
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
	//Конструктор копирования
	Datetime(const Datetime &other);
	//Деструктор
	~Datetime() = default;

	//Оператор присваивания
	const Datetime& operator = (const Datetime& other);

	//Установить текущие время и дату
	void setNow();

	//Получить дату и время в виде строки
	const string getStrAll() const;
	//Получить дату в виде строки
	const string getStrDate() const;
	//Получить время в виде строки
	const string getStrTime() const;
};


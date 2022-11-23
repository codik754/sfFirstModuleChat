// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//Файл datetime.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "datetime.h"
#include "chat.h"
#include <ctime>
#include <sstream>

//Подсветка времени
//SetConsoleTextAttribute(hConsole_, 15);
//Конструктор по умолчанию
Datetime::Datetime() {
    std::time_t t = std::time(nullptr);
    std::tm* now = localtime(&t);

    sec_ = now->tm_sec;
    min_ = now->tm_min;
    hour_ = now->tm_hour;
    day_ = now->tm_mday;
    month_ = now->tm_mon + 1;
    year_ = now->tm_year + 1900;
}


//Установить текущие время
void Datetime::setNow() {
    std::time_t t = std::time(nullptr);
    std::tm* now = localtime(&t);

    sec_ = now->tm_sec;
    min_ = now->tm_min;
    hour_ = now->tm_hour;
    day_ = now->tm_mday;
    month_ = now->tm_mon + 1;
    year_ = now->tm_year + 1900;
}

//Получить секунды
int Datetime::getSec() const {
    return sec_;
}

//Получить минуты
int Datetime::getMin() const {
    return min_;
}

//Получить часы
int Datetime::getHour() const {
    return hour_;
}

//Получить день
int Datetime::getDay() const {
    return day_;
}

//Получить месяц
int Datetime::getMonth() const {
    return month_;
}

//Получить год
int Datetime::getYear() const {
    return year_;
}

//Получить дату и время в виде строки
const string Datetime::getStr() const {
    std::ostringstream os;
    os << day_ << "." << month_ << "." << year_ << "  " << hour_ << ":" << min_ << ":" << sec_;
    return os.str();
}

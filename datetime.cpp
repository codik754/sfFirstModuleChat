// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//���� datetime.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "datetime.h"
#include "chat.h"
#include <ctime>
#include <sstream>

//��������� �������
//SetConsoleTextAttribute(hConsole_, 15);
//����������� �� ���������
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


//���������� ������� �����
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

//�������� �������
int Datetime::getSec() const {
    return sec_;
}

//�������� ������
int Datetime::getMin() const {
    return min_;
}

//�������� ����
int Datetime::getHour() const {
    return hour_;
}

//�������� ����
int Datetime::getDay() const {
    return day_;
}

//�������� �����
int Datetime::getMonth() const {
    return month_;
}

//�������� ���
int Datetime::getYear() const {
    return year_;
}

//�������� ���� � ����� � ���� ������
const string Datetime::getStr() const {
    std::ostringstream os;
    os << day_ << "." << month_ << "." << year_ << "  " << hour_ << ":" << min_ << ":" << sec_;
    return os.str();
}

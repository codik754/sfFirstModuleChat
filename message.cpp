// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

//���� message.cpp
#include "message.h"

//����������� �� ���������
Message::Message() : sendedFrom_("UNKNOWN"), sendedTo_("UNKNOWN"), text_("UNKNOWN"), dateandtime_() {}

//����������� � �����������
Message::Message(const string& from, const string& to, const string& text) : sendedFrom_(from), sendedTo_(to), text_(text), dateandtime_() {}

//������ �� ���� ���������� ���������
const string& Message::getSendedFrom() const {
	return sendedFrom_;
}

//������ ���� ���������� ���������
const string& Message::getSendedTo() const {
	return sendedTo_;
}

//�������� ����� ���������
const string& Message::getText() const {
	return text_;
}

//�������� ���� � �����
const string Message::getDatetime() const {
	return dateandtime_.getStr();
}

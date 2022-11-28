// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "chat.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

//Добавить наблюдателя на подписку
void Chat::attach(IObserver* observer) {
    subscribers_.push_back(observer);
}

//Исключить наблюдателя из подписки
void Chat::dettach(IObserver* observer) {
    subscribers_.remove(observer);
}

//Разослать информацию про общий чат
void Chat::notifyAboutAll() {
    for (auto &subscriber : subscribers_) {
        subscriber->updateInformationAll();
    }
} 

//Проинформировать про личное сообщение
void Chat::notifyAboutSelf(const string& login) {
  for (auto subscriber : subscribers_) {
        if (subscriber->isThisI(login)) {
            subscriber->updateInformationSelf();
        }
   }
}

//Получить общее количество общих сообщений
unsigned int Chat::getAmountAll() const {
    return amountAll_;
}

//Показать первое меню
char Chat::showHelloMenu() {
    char choice = '0';
    while (true) {
        setColorToConsole(6);
        cout << "Добрый день! Добро пожаловать в чат. Что будем делать?" << endl;
        cout << "1. Войти" << endl;
        cout << "2. Регистрация" << endl;
        cout << "q - Выход" << endl;
        setColorToConsole(3);
        cout << endl << "Введите символ: ";
        cin >> choice;
        if (choice == '1' || choice == '2' || choice == 'q') {
            break;
        }
        else {
            system("cls");
            setColorToConsole(4);
            cout << "Команды " << choice << " не знаю!!!" << endl;
            setColorToConsole(15);
            system("pause");
            system("cls");
        }
    }
    setColorToConsole(15);
    system("cls");
    return choice;
}

//Показать меню регистрации
void Chat::showRegistrationMenu() {
    string tname;
    string tpassword;
    string tlogin;
    while (true) {
        setColorToConsole(6);
        cout << "Введите регистрационные данные" << endl;
        cout << "Имя: ";
        setColorToConsole(3);
        cin >> tname;
        setColorToConsole(6);
        cout << "Логин: ";
        setColorToConsole(3);
        cin >> tlogin;
        setColorToConsole(6);
        cout << "Пароль: ";
        setColorToConsole(3);
        cin >> tpassword;
        if (checkLogin(tlogin)) {
            system("cls");
            setColorToConsole(4);
            cout << "Логин " << tlogin << " занят!" << endl;
            setColorToConsole(15);
            system("pause");
            system("cls");
        }
        else {
            break;
        }
    }
    setColorToConsole(15);

    //Создаем пользователя и добавляем в вектор
    users_.push_back(User(tlogin, tpassword, tname, this));
    //Подписываем последнего добавленного пользователя на уведомления
    
   

    //vector<User>::iterator itu = users_.end();
    
    //--itu;
    //itu->subscribe();
    users_[users_.size() - 1].subscribe();
    
    
    //Отправляем пользователю личное сообщения от администратора
    addMessage("admin", tlogin, "Welcome to the chat! We are glad to see you here. Make yourself at home!");

    system("cls");
    setColorToConsole(10);
    cout << "Поздравляю! Вы зарегистрировались!" << endl;
    setColorToConsole(15);
    system("pause");
    system("cls");
}

//Получить общее количество личных сообщений для пользователя
unsigned int Chat::getAmountSelfMessage(const string &login) const {
    unsigned int amount = 0;

    for (auto& message : message_) {
        if (message.checkToSendedTo(login)) {
            ++amount;
        }
    }

    return amount;
}

//Показать меню для входа
void Chat::showLogIn() {
    string tlogin;
    string tpassword;
    setColorToConsole(6);
    cout << "Введите данные для входа " << endl;
    cout << "Логин: ";
    setColorToConsole(3);
    cin >> tlogin;
    setColorToConsole(6);
    cout << "Пароль: ";
    setColorToConsole(3);
    cin >> tpassword;
    currentUser = getUser(tlogin, tpassword);
    system("cls");
    if (!currentUser) {
        setColorToConsole(4);
        cout << "Логин или пароль введены неверно!" << endl;
        setColorToConsole(15);
        system("pause");
        system("cls");
        return;
    }
    setColorToConsole(15);
    showChatMenu();
}

//показать меню общего чата
void Chat::showChatMenu() {
    
    
    short type = 1;//тип чата(общий или личнные сообщения)
    char choice = '0';//выбор в чате
    Datetime date;

    while (true) {
        
        if (type == 1){
            setColorToConsole(6);
            cout << "Общий чат" << endl;
            date.setNow();
            cout << date.getStrDate() << endl;
            cout << date.getStrTime() << endl;
           
            cout << "________________________________________________________________________________________________" << endl;
            if (amountAll_ == 0) {
                setColorToConsole(9);
                cout << endl << "Сообщений нет" << endl;
            }
            else {
                unsigned int tnewAllMessage = amountAll_ - currentUser->getNewAllMessages();
                unsigned int i = 1;
               // cout << "MESSAGE: " << tnewAllMessage << endl;
                for (auto& message : message_) {
                    if (message.checkToSendedTo("all")) {
                        setColorToConsole(224);//224
                        cout << "[" << message.getSendedFrom() << "]" << endl;
                        setColorToConsole(3);
                        cout << message.getText() << endl;
                        SetConsoleMode(hConsole_, ENABLE_PROCESSED_OUTPUT);//это надо, чтобы не появлялась лишняя цветная полоса при переносе
                        setColorToConsole(11);
                        cout << message.getDatetime() << endl;
                        cout << endl;
                        if (i == tnewAllMessage && tnewAllMessage != amountAll_ && currentUser->getIsSubscribes()) {
                            setColorToConsole(6);
                            cout << "==================Новое===================" << endl;
                        }
                        ++i;
                    }
                }
            }
            setColorToConsole(6);
            cout << "________________________________________________________________________________________________" << endl;
            unsigned int tself = currentUser->getNewSelfMessages();
            string tstrtemp;
            if (tself > 0) {
                tstrtemp = "(" + std::to_string(tself) + ")";
            }
            cout << "1 - Обновить чат   2 - Личные сообщения" << (currentUser->getIsSubscribes() ? tstrtemp : "" ) << "  3 - Написать сообщение  4 - " <<
                (currentUser->getIsSubscribes() ? "Отписаться от уведомлений" : "Подписаться на уведомления") << endl;
            cout << "q - Выход" << endl;
            cout << "Введите символ: ";
            setColorToConsole(3);
            cin >> choice;
            //currentUser->getLogin() << "  " << currentUser->getPassword() << endl;
            currentUser->resetNewAllMessages();
            setColorToConsole(15);
        }
        
        if (type == 2) {
            currentUser->setAmountSelfMessages(getAmountSelfMessage(currentUser->getLogin()));
            setColorToConsole(6);
            cout << "Личные сообщения" << endl;
            date.setNow();
            cout << date.getStrDate() << endl;
            cout << date.getStrTime() << endl;
            cout << "________________________________________________________________________________________________" << endl;
            if (currentUser->getAmountSelfMessages() == 0) {
                setColorToConsole(9);
                cout << endl << "Сообщений нет" << endl;
            }
            else {
                unsigned int tAmountSelfMessage = currentUser->getAmountSelfMessages();
                unsigned int tnewSelfMessage = tAmountSelfMessage - currentUser->getNewSelfMessages();
                unsigned int i = 1;
                
            //    cout << tnewSelfMessage << endl;

                string tlogin = currentUser->getLogin();
                for (auto& message : message_) {
                    if (message.checkToSendedTo(tlogin)) {
                        setColorToConsole(224);
                        cout << "[" << message.getSendedFrom() << "]" << endl;
                        setColorToConsole(3);
                        cout << message.getText() << endl;
                        SetConsoleMode(hConsole_, ENABLE_PROCESSED_OUTPUT);//это надо, чтобы не появлялась лишняя цветная полоса при переносе
                        setColorToConsole(11);
                        cout << message.getDatetime() << endl;
                        cout << endl;
                        if (i == tnewSelfMessage && tnewSelfMessage != tAmountSelfMessage && currentUser->getIsSubscribes()) {
                            setColorToConsole(6);
                            cout << "==================Новое===================" << endl;
                        }
                      
                        ++i;
                    }
                }
            }
            setColorToConsole(6);
            cout << "________________________________________________________________________________________________" << endl;
            unsigned int tall = currentUser->getNewAllMessages();
            string tstrtemp;
            if (tall > 0) {
                tstrtemp = "(" + std::to_string(tall) + ")";
            }
            cout << "1 - Общий чат" << (currentUser->getIsSubscribes() ? tstrtemp : "") << "  2 - Обновить чат" << "  3 - Написать сообщение  4 - " <<
                (currentUser->getIsSubscribes() ? "Отписаться от уведомлений" : "Подписаться на уведомления") << endl;
            cout << "q - Выход" << endl;
            cout << "Введите символ: ";
            setColorToConsole(3);
            cin >> choice;
            //currentUser->getLogin() << "  " << currentUser->getPassword() << endl;
            currentUser->resetNewSelfMessages();
            setColorToConsole(15);
        }

        if (choice == 'q') {
            break;
        }
        else if (choice == '1') {
            if (type == 2) {
                type = 1;
            }
            system("cls");
            continue;
        }
        else if (choice == '2') {
            if (type == 1) {
                type = 2;
            }
            system("cls");
            continue;
        }
        else if (choice == '3') {
            system("cls");
            showWriteMessageMenu();
        }
        else if(choice == '4') {
            if (currentUser->getIsSubscribes()) {
                currentUser->unscribe();
            }
            else {
                currentUser->subscribe();
            }
        }
        system("cls");
       
    }
    
    
    system("cls");
}

//установить цвет в консоле
void Chat::setColorToConsole(WORD n) {
    SetConsoleTextAttribute(hConsole_, n);
}

//проверка существует ли польозователь с таким логином
bool Chat::checkLogin(const string& login) {
    for (const auto& user : users_) {
        if (user.checkLogin(login)) {
            return true;
        }
    }
    return false;
}

//Проверка существует ли пользователь с таким логином. Если да, то правильно ли введен пароль
User* Chat::getUser(const string& login, const string& password) {
    for (auto& user : users_) {
        if (user.checkLogin(login)) {
            if (user.checkPassword(password)) {
                return &user;
            }
        }
    }
    return nullptr;
}

//Добавить сообщение
void Chat::addMessage(const string& from, const string& to, const string& text) {
    message_.emplace_back(Message(from, to, text));
    if (to == "all") {
        notifyAboutAll();
        ++amountAll_;
    }
    else {
        notifyAboutSelf(to);
    }
}

//Показать меню для написания сообщений
void Chat::showWriteMessageMenu() {
    string to;
    string text;
    while (true) {
        setColorToConsole(6);
        cout << "Кому писать сообщение(all в общий чат): ";
        setColorToConsole(3);
        cin >> to;
        setColorToConsole(6);
        cout << "Текст сообщения: ";
        setColorToConsole(3);
        cin.ignore();
        getline(cin, text);
        if (text.empty()) {
            system("cls");
            setColorToConsole(4);
            cout << "Поле сообщение пустое!!!" << endl;
            setColorToConsole(15);
            system("pause");
            system("cls");
        }
        else if (!checkLogin(to) && to != "all") {
            system("cls");
            setColorToConsole(4);
            cout << "Пользователь с логином " << to << " не зарегистрирован в чате!" << endl;
            setColorToConsole(15);
            system("pause");
            system("cls");
        }
        else {
            break;
        }
    }
    addMessage(currentUser->getLogin(), to, text);
    setColorToConsole(15);
    system("cls");
}
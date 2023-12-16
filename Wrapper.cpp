#include <iostream>

using namespace std;

class Notification {
public:
    virtual ~Notification() = default;

    virtual void send() = 0;
};

class EmailNotification : public Notification {
    string email_address_;
public:
    EmailNotification(const string& email_address) : email_address_(email_address) {}

    void send() override {
        cout << "Sending email notification to " << email_address_ << endl;
    }
};

class SMSNotification : public Notification {
    string phone_number_;
public:
    SMSNotification(const string& phone_number) : phone_number_(phone_number) {}

    void send() override {
        cout << "Sending SMS notification to " << phone_number_ << endl;
    }    
};

class LoggingDecorator : public Notification {
    Notification* notification_;
public:
    LoggingDecorator(Notification* notification) : notification_(notification) {}

    void send() override {
        cout << "Logging notification" << endl;
        notification_->send();
    }
};

int main() {
    EmailNotification emailNotification("john.doe@example.com");
    SMSNotification smsNotification("+1 234 567 890");

    LoggingDecorator loggingDecorator1(&emailNotification);
    loggingDecorator1.send();

    LoggingDecorator loggingDecorator2(&smsNotification);
    loggingDecorator2.send();

    return 0;
}

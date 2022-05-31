#ifndef DATE_H
#define DATE_H
#include <QString>
#include <QStringList>
#include <QCharRef>
class Date
{
private:
    int day, month, year;
public:
    Date(int = 1, int = 1, int = 2000);
    ~Date();

    QString getDay();
    QString getMonth();
    QString getYear();

    void setDay(int = 1);
    void setMonth(int = 1);
    void setYear(int = 2000);
    void setDate(QString );
    QString getDate();
};

#endif // DATE_H

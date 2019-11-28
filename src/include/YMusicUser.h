#ifndef YMUSICUSER_H
#define YMUSICUSER_H

#include <QObject>

class YMusicUser : public QObject
{
    Q_OBJECT
public:
    YMusicUser();
    Q_PROPERTY(bool isLoggedIn READ getIsLoggedIn NOTIFY isLoggedInChanged)

public slots:
    bool getIsLoggedIn() const;
    void tryToLogIn(const QString&, const QString&);

signals:
    void isLoggedInChanged();

private:
    bool _isLoggedIn;
};

#endif // YMUSICUSER_H

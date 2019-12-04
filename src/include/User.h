#ifndef USER_H
#define USER_H

#include <IUserInfo.h>

class User : public IUserInfo
{
public:
    User();
    bool isLoggedIn() const override;

private:
    bool _loggedIn;
};

#endif // USER_H

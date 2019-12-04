#include "User.h"

User::User() : _loggedIn(false)
{
}

bool User::isLoggedIn() const
{
    return _loggedIn;
}

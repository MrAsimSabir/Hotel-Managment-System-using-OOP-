#include "Admin.h"
const string& Admin::getUsername() const
{
    return Username;
}
const string& Admin::getPassword() const
{
    return Password;
}
void Admin::setUsername(const string& username)
{
    Username = username;
}
void Admin::setPassword(const string& password)
{
    Password = password;
}

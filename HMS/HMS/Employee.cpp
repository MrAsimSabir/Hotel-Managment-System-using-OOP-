#include "Employee.h"
Employee::Employee(Employee& other)
{
    Name = other.Name;
    EmployeeType = other.EmployeeType;
    EmployeeId = other.EmployeeId;
    Age = other.Age;
    Gender = other.Gender;
    Username = other.Username;
    Password = other.Password;
    PhoneNO = other.PhoneNO;
    Address = other.Address;
}
const string& Employee::getEmployeeType()const {
    return EmployeeType;
}
void Employee::setEmployeeType(const string& emptype) {
    EmployeeType = emptype;
}
const string& Employee::getEmployeeId() const
{
    return EmployeeId;
}

const string& Employee::getUsername() const
{
    return Username;
}

const string& Employee::getPassword() const
{
    return Password;
}
void Employee::setEmployeeId(const string& employeeId)
{
    EmployeeId = employeeId;
}

void Employee::setUsername(const string& username)
{
    Username = username;
}

void Employee::setPassword(const string& password)
{
    Password = password;
}
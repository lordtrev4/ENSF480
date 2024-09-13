/*
*   File Name: company.cpp
*   Assignment: Lab 1 Exercise C
*   Completed by: Trevor Nguyen and Zachary Lam
*   Submission Date: Sept 13, 2024 
*/

#include <string>
#include <vector>
using namespace std;

class Company {
    private:
        Date dateEstablished;
        Address address;
        string Name;
    public:
};

class Employee{
    private:
        Name name;
        Address address;
        Date dateOfBirth;
        string employeeState;
    public:
};

class Customer {
    private:
        Name name;
        Address address;
        string phoneNumber;
    public:
};

class Name  {
    string firstName;
    string middleName;
    string lastName;
};

class Address {
    private:
        string street;
        string city;
        string province;
        string country;
        string postalCode;
    public:
};

class Date {
    private:
        string month;
        int day;
        int year;
    public:
};
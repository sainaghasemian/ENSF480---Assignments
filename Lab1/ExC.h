/*
* File Name: ExC.h
* Assignment: Lab 1 Exercise C
* Completed by: Rachel Dalton & Saina Ghasemian-Roudsari
* Submission Date: Sept 21, 2022
*/

#include <vector>
#include <string>

#ifndef EXC_H
#define EXC_H

using namespace std;

class Company
{
    private:
        string companyName;
        string companyAddress;
        Date dateEstablished;
        vector<Employee> employees;
        vector<Customer> customers;
};

class Date
{
    private:
        string day;
        string month;
        string year;
};

class Person
{
    private:
        Name name;
        Address address;
};

class Employee:Person
{
    private:
        Address address;
        Date dateOfBirth;
        string state;
};

class Customer:Person
{
    private:
        string phone;
};

class Address
{
    private:
        string street;
        string city;
        string postalCode;
        string country;
};

class Name
{
    private:
        string firstName;
        string midName;
        string lastName;
};

#endif
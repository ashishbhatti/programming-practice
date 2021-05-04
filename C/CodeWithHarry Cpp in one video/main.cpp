/* C++ is a general purpose, statically typed, obejct oriented programming language.

Made by Bjarne Stroustrup in 1979. 
Officially released in 1985 as a superset of C language. (Not a strict superset). */

#include <iostream> //preprocessor command
#include <string>
using namespace std;

// f(x) = x^2 + 2
int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

class Employee
{
public:
    string name;
    int salary;

    Employee(string n, int s, int sp) // this function is called constructor
    {
        this->name = n;
        this->salary = s;
        this->secretPassword = sp;
    }

    void printDetails()
    {
        cout << "The name of our first employee is " << this->name << " and his salary is " << this->salary << " dollars." << endl;
    }

    void getSecretPassword()
    { // public methods in class can access private variables / methods
        cout << "The secret password of employee is " << this->secretPassword;
    }

private:
    int secretPassword;
};

class Programmer : public Employee
{
public:
    int errors;
};

int main()
{
    // cout << "Hello World!" << " Ashish" << endl; //console output, endl for newline
    // cout << "Next Line";
    // int a, b, c;
    // short sa = 9;   // variables are case sensitive
    // cout << sa;

    //camelCase Notation
    // int marksInMaths = 83;
    // cout << "The marks of the student in maths is " << marksInMaths;

    // short a;
    // int b;
    // long c;
    // long long d;
    // float const score = 45.32;  // const keyword for a constant variable
    // double score2 = 45.32;
    // long double score3 = 45.332;
    //score = 34.2;  // Updation of value
    // cout << "The score is " << score;
    // string harry = "Harry";

    // int a, b;
    // cout << "Enter first number" << endl;
    // cin >> a;

    // cout << "Enter second number" << endl;
    // cin >> b;

    // cout << "a + b is " << a + b << endl;
    // cout << "a - b is " << a - b << endl;
    // cout << "a * b is " << a * b << endl;
    // cout << "a / b is " << (float)a / b << endl;

    // int age;
    // cout << "Enter your age" << endl;
    // cin >> age;

    // if (age > 150 || age < 4)
    // {
    //     cout << "Invalid age";
    // }
    // else if (age >= 18)
    // {
    //     cout << "You can vote";
    // }
    // else
    // {
    //     cout << "You cannot vote";
    // }

    // switch (age)
    // { // break is important because if a case comes true
    //     // and no break was put in it, it will execute all the cases below

    // case 12:
    //     cout << "You are 12 years old" << endl;
    //     break;
    // case 18:
    //     cout << "You are 18 years old" << endl;
    //     break;
    // default:
    //     cout << "You are neither 12 nor 18 years old";
    //     // break; // No need of break here
    // }

    //loops

    // int index = 0;
    // while (index < 34)
    // {
    //     cout << "We are at index number " << index << endl;
    //     index = index + 1;
    // }

    // do while loops executes once and then executes if condition is true
    // do
    // {
    //     cout << "We are at index number " << index << endl;
    //     index = index + 1;

    // } while (index > 3453);

    // for (int i = 1; i <= 34; i++)
    // {
    //     cout << "The value of i is " << i << endl;
    // }

    // int a, b;
    // cout << "Enter first number" << endl;
    // cin >> a;

    // cout << "Enter second number" << endl;
    // cin >> b;

    // cout << "The function returned " << add(a,b);

    // int arr[] = {1, 3, 6};
    // //arr index  0  1  2

    // //cout << arr[1];

    // int marks[6];

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "Enter the marks of " << i <<"th student" << endl;
    //     cin >> marks[i];

    // }

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << "Marks of " << i <<"th student is " << marks[i] << endl;

    // }

    // int arr2d[2][3] = {{1, 2, 3},
    //                    {4, 5, 6}};

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "The value at " << i << "," << j << " is " << arr2d[i][j] << endl;
    //     }
    // }

    // typecasting

    // int a = 343;
    // float b = 87.94;
    // cout << (float) a/34 << endl;

    // cout <<(int) b;  // does not roundoff, only typecase

    // string name = "harry";
    // cout << "The name is " << name << endl;
    // cout << "The length of name is " << name.length() << endl;
    // cout << "The name is " << name.substr(1,551) << endl;
    // cout << "The name is " << name.substr(2,3) << endl;

    // pointers
    // int a = 34;
    // int *ptra;
    // ptra = &a;
    // cout << "The value of a is " << a << endl;
    // cout << "The value of a is " << *ptra << endl; // Dereferencing a pointer
    // cout << "The address of a is " << &a << endl;
    // cout << "The address of a is " << ptra << endl; // cout doesn't take a type or placefolder

    // Object Oriented Programming
    // It is a way of programming in which we make classes and objects.
    // A class is a template / blueprint.
    // Example : If you want to make bills, you would not want to create space for heading,
    // create space for date, create space for grand total.
    // You would want to make a template once and edit later.

    Employee har("Harry constructor", 344, 324432);
    // har.name = "harry";
    // har.salary = 100;
    // cout << "The name of our first employee is " << har.name << " and his salary is " << har.salary << " dollars." << endl;
    har.printDetails();
    har.getSecretPassword();

    return 0;
}

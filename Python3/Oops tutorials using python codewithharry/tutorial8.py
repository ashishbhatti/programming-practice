'''
Video 8:
Magic / Dunder Methods in Python

The methods with underscores __methodname__ are called dunder methods
Example : __init__ is called dunder init, it means its a special method, its a constructor, it runs automatically when you create an object

'''

class Employee:
    increment = 1.5
    noOfEmployees = 0
    def __init__(self, fname, lname, salary):
    # constructor 
        self.fname = fname
        self.lname = lname
        self.salary = salary
        Employee.noOfEmployees += 1
    
    def increase(self):
        self.salary = int(self.salary * self.increment) #searches for increment variable in this instance then if not found in class.

    @classmethod
    def change_increment(cls,amount):
        cls.increment = amount
    
    @classmethod
    def from_str(cls, emp_string):
        fname, lname, salary = emp_string.split("-")
        return cls(fname, lname, salary)

    @staticmethod
    def isOpen(day):
        if day == "sunday":
            return False
        else :
            return True

    def __add__(self,other):
        return self.salary + other.salary

    def __repr__(self):
        # determines the output of print(object)
        return 'Employee({}, {}, {})'.format(self.fname,self.lname,self.salary)

    def __str__(self):
        return 'The name of employee is {}.'.format(self.fname)


harry = Employee('harry', 'jackson', 99000)
rohan = Employee('rohan', 'agarwal', 9)

# # print('98' + '12') # on two strings I use add dunder method
# # Example of add dunder method
# a = 6
# # print(a.__add__(7)) # prints 6+7; so when I use + in print it runs __add__ dunder method
# print(a.__mul__(7))

# print(harry + rohan) # gives error if operation not defined by dunder add method

# print(harry) # prints location of harry object if repr method is not defined in class

# print(str(harry)) #works same as print(harry) (without repr) if str method is not explicitly defined

 
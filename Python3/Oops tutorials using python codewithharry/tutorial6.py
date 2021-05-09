'''
Video 6:
Static methods in python oops

It is a method of a class which doesn't require instance
as well as class vaiables as argument.

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


    
#shubham = Employee('shubham', 'jackson', 88000)
print(Employee.isOpen('monday'))

# harry = Employee('harry','jackson',44000)  
# lovish = Employee.from_str("lovish-jackson-76000")
# rohan = Employee('rohan','das',74000)
# print(lovish.salary)
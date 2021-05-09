'''
Video 4:
Class methods as alternative contructor


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


    

harry = Employee('harry','jackson',44000)  

lovish = Employee.from_str("lovish-jackson-76000")

rohan = Employee('rohan','das',74000)

print(lovish.salary)
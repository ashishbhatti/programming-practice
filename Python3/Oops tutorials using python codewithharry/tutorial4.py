'''
Video 3:
Class Methods

We need to run such a function which deals only with 
class variables and not with instance variables

# def change_increment(self):
    #     # here we have to pass self but it is inefficient as 
    #     # to change only a class variable I do not want 
    #     # to pass whole object as an argument
    #     increment = 1.5

so we make a class method. Old function takes instance as an argument
class method takes class as an argument
we need to put a decorator first


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

    

harry = Employee('harry','jackson',44000)  # Denoting an employee with Employee object

rohan = Employee('rohan','das',44000)


print(harry.salary)
Employee.change_increment(4)
harry.increase()
print(harry.salary)

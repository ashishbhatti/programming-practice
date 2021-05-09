'''
Video 1:
Class is a template or blueprint for code reuse
Class template has attributes and methods
Attributes i.e data of employee like name, email, salary.
Methods i.e functions like addSalary(x) to increase the salary by amount x

constructor : a function of a class which automatically
fills the values in instance variables.
name is __init__ has first argument self
Hence we can initialize at the time of making an object.

'''

class Employee:

    def __init__(self, fname, lname, salary):
    # constructor 
        self.fname = fname
        self.lname = lname
        self.salary = salary
    

# creating objects
harry = Employee('harry','jackson',44000)  # Denoting an employee with Employee object
rohan = Employee('rohan','das',44000)



print(harry.fname, rohan.fname)
#print(harry, rohan)


'''
Video 2:
Instance variables vs class variables.

Instance variables : Variables which are filled with the 
instance of the object.

Class variables : Variables common to all instances of objects
or variable specific for the class. Ex. no of allowed vacations

'''

class Employee:

    increment = 1.5
    noOfEmployees = 0
    def __init__(self, fname, lname, salary):
    # constructor 
        self.fname = fname
        self.lname = lname
        self.salary = salary
        #self.increment = 1.4
        Employee.noOfEmployees += 1
    
    def increase(self):
        # self.salary = self.salary * increment  # incorrect increment not defined
         self.salary = int(self.salary * self.increment) #searches for increment variable in this instance then if not found in class.
        # self.salary = int(self.salary * Employee.increment) # doesn't search in instance variables, directly goes to class variables


print(Employee.noOfEmployees)
# creating objects
harry = Employee('harry','jackson',44000)  # Denoting an employee with Employee object
print(Employee.noOfEmployees)

rohan = Employee('rohan','das',44000)
print(Employee.noOfEmployees)


print(harry.__dict__) # to see instance variables
harry.increment = 9
#when you call a function on an object, self as argument is passes
#harry.increase()
#print(harry.salary)
#print(harry.__dict__)
# print(Employee.__dict__)



#print(harry.fname, rohan.fname)
#print(harry, rohan)


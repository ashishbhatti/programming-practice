'''
Video 9:
Property Decorators, Setters & Deleters

'''

class Employee:
    increment = 1.5
    noOfEmployees = 0
    def __init__(self, fname, lname, salary):
    # constructor 
        self.fname = fname
        self.lname = lname
        self.salary = salary
        # self.email = fname+lname + '@emaii.com'
        # self.email = self.fname + self.lname + '@emaii.com' # both comments don't update the email, when lname is changed
        Employee.noOfEmployees += 1
    
    def increase(self):
        self.salary = int(self.salary * self.increment) #searches for increment variable in this instance then if not found in class.

    @classmethod
    def change_increment(cls,amount):
        cls.increment = amount

    @property
    def email(self):
        if self.fname == None:
            return 'email not set'
        else :
            return self.fname +'.'+ self.lname + '@email.com'

    @email.setter
    def email(self, given_email):
        # self.email = given_email # gives error of maximum recursion limit reached, so to change we change fname and lname instead
        name_list = given_email.split('@')[0].split('.')
        self.fname = name_list[0]
        self.lname = name_list[1]

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

    @email.deleter
    def email(self):
        self.fname = None
        self.lname = None

if __name__ == '__main__':
    harry = Employee('harry', 'jackson', 99000)
    rohan = Employee('rohan', 'agarwal', 9)
    print(harry.email, rohan.email)
    rohan.lname = 'Khanna' 
    print(rohan.email)
    rohan.email = 'khanna.rohan@gmail.com' #error can't assign to function call
    print(rohan.email)
    del rohan.email
    print(rohan.email)


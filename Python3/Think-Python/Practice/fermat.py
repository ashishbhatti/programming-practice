'''
Checks fermats last theorem
'''

from __future__ import print_function, division

def check_fermat(a,b,c,n):
    '''
    Checks fermats last theorem and prints if it holds for the numbers
    '''
    if n<=2:
        print("Error! n should be greater than 2")
        return
    lhs = a**n + b**n
    rhs = c**n
    if lhs == rhs:
        print("Holy, smokes, Fermat was wrong!")
    else :
        print("No, that doesn't work.")

def fermat ():
    '''
    Takes 4 numbers as input and checks if they satisfy
    fermats last theorem
    '''
    a = int(input("Please enter positive integer\n"))
    b = int(input("Please enter positive integer\n"))
    c = int(input("Please enter positive integer\n"))
    n = int(input("Please enter a number greater than 2\n"))

    check_fermat(a,b,c,n)

if __name__ == '__main__':
    fermat ()
from __future__ import print_function, division

def is_triangle(a,b,c):
    '''
    Checks id a,b,c form a triangle
    '''
    if (a + b) <= c:
        print("No")
    elif (b+c) <= a:
        print("No")
    elif (a+c) <= b:
        print("No")
    else:
        print("Yes")


def try_triangle():
    '''
    Checks if inputs given by the user for a triangle
    '''
    a = float(input("Please enter a : "))
    b = float(input("Please enter b : "))
    c = float(input("Please enter c : "))

    is_triangle(a,b,c)

if __name__ == '__main__':
    try_triangle()        

        
        
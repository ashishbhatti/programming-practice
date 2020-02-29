import math

def area(radius):
    '''
    Returns area of the circle 
    '''
    return math.pi*radius*2

def absolute_value(x):
    '''
    Returns absolute value of x
    '''
    if x<0:
        return -x
    else:
        return x
    

def compare(x,y):

    if x>y:
        return 1
    elif x==y:
        return 0
    else:
        return -1

def distance(x1,y1,x2,y2):
    '''
    Calculates distance between two points 1 & 2
    '''
    dx = x2-x1
    dy = y2-y1
    ds = math.sqrt(dx**2 + dy**2)
    return ds

def hypotenuse(x,y):
    '''
    Returns hypotenuse
    '''
    hyp = math.sqrt(x**2 + y**2)
    return hyp

def circle_area(xc,yc,xp,yp):
    '''
    Returns area of circle 
    xc,yc is the centre coordinates
    xp,yp is the perimeter point coordinates
    '''
    return area(distance(xc,yc,xp,yp))
    
def is_divisible(x,y):
    '''
    checks if x is divisible by y
    '''
    return x%y == 0

def is_between(x,y,z):
    '''
    returns true if x<= y <=z
    '''
    return x<=y<=z        
    
def factorial(n):
    '''
    Computes factorial of a positive number n
    '''
    if not isinstance(n,int):
        print('Factorial is only defined for integers.')
        return None
    elif n<0:
        print('Factorial is not defined for negative integers')
        return None    
    elif n == 0:
        return 1
    else:
        return n*factorial(n-1)

def fibonacci(n):
    '''
    Computes n th term of fibonacci series 
    '''
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)
    

'''
Solutions to exercises
'''
def b(z):
    prod = a(z,z)
    print(z,prod)
    print(prod,'\n')
    return prod

def a(x,y):
    x = x+1
    print(x*y,'\n')
    return x*y

def c(x,y,z):
    total = x+y+z
    square = b(total)**2
    print(square,'\n')
    return square

def ack(m,n):
    '''
    Evaluates Ackermann function
    '''
    space = ' ' * (4 * (m+n+1))
    if m<0 or n<0:
        print("m & n should both be positive")
        return
    elif m == 0:
        print(space,'returning',n+1)
        return n+1
    elif m>0 & n==0:
        result = ack(m-1,1)
        print(space,'returning',result)
        return result
    elif m>0 & n>0:
        result = ack(m-1, ack(m,n-1) )
        print(space,'returning',result)
        return result






if __name__ == '__main__':
    #print(factorial(-2))

    ''' Q6.1 main '''
    #x = 1
    #y = x+1
    #print (c( x, y+3, x+y ))

    '''
    Sol 1 = Stack diagram
    main      : x = 1, y = 2               | print 8100
    c         : x=1, y=5, z=3, total = 9   | return square = 8100
    b         : z=9                        | return prod = 90
    a         : x=9, y=9, x=10             | return 90

    '''

    '''Q6.2 main '''
    print(ack(3,4))

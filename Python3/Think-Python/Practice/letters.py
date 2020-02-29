'''
This file contains the functions to create a typewriter (capitals)
using the turtle package of python
'''
from __future__ import print_function, division
import turtle
from polygon import circle3, arc2

''' preliminaries 0'''

def bk(t,length):
    t.bk(length)

def pu(t):
    t.pu()

def pd(t):
    t.pd()

def fd(t,length):
    t.fd(length)

def fdbk(t,length):
    fd(t,length)
    pu(t)
    bk(t,length)
    pd(t)

def skip(t,length):
    pu(t)
    fd(t,length)
    pd(t)

def skipb(t,length):
    pu(t)
    bk(t,length)
    pd(t)


''' preliminaries 1 '''

def vline (t,length):
    '''
    Draws a verticle line using turtle t and of length height
    leaves the turtle facing right on the top corner
    '''
    t.lt(90)
    t.fd(length)
    t.rt(90)

def hline (t,length):
    '''
    Draws a horiontal line of length size and leaves the turlte
    at final position
    '''
    fd(t,length)

''' preliminaries 2 '''

def backvline(t,length):
    '''
    draws a verticle line by going below the present point
    leaves the turtle facing right
    '''
    t.lt(90)
    bk(t,length)
    t.rt(90)

def gammab (t,length):
    '''
    traces the turtle along a post back to its original position 
    without leaving a trail
    '''
    pu(t)
    bk(t,length)
    t.lt(90)
    t.bk(2*length)
    t.rt(90)
    pd(t)

def gamma(t,length):
    '''
    Draws a verticle line of 2*length and 
    a horizontal line of length size on top of verticle line

    '''
    vline(t,2*length)
    hline(t,length)

def rise(t,height):
    '''
    turtle rises to height
    '''
    pu(t)
    vline(t,height)
    pd(t)

def fall(t,height):
    '''
    turtle falls below by height
    '''
    pu(t)
    backvline(t,height)
    pd(t)


def floatline(t,length,height):
    '''
    a line of length size with floats 'height' high
    '''
    rise(t,height)
    hline(t,length)

def floatlineb(t,length,height):
    '''
    traces a floatline back to its starting position
    without leaving a trail
    '''
    pu(t)
    bk(t,length)
    fall(t,height)


''' Premilimaries 3 '''

def post(t,length):
    '''
    Draws a post and leaves the turtle at original position
    height : 2*Length, Width = length
    '''
    gamma(t,length)
    gammab(t,length)

def flyline(t,length,height):
    ''' 
    Draws a floating line and returns back to the initial position
    '''
    floatline(t,length,height)
    floatlineb(t,length,height)

def stump(t,distance,height):
    '''
    Draws a verticle line of height at a distance from current position
    '''
    skip(t,distance)
    vline(t,height)
    backvline(t,height)
    skipb(t,distance)

def disflyline(t,distance,length,height):
    skip(t,distance)
    flyline(t,length,height)
    skipb(t,distance)

def diagonal(t,x,y):
    '''
    Draws a slant line and returns to original position
    x is the x coordinate of final point of line
    y is the y coordinate od final point of line
    '''
    from math import atan2, sqrt, pi
    angle = atan2(y,x) * 180/pi
    length = sqrt(x**2 + y**2)
    t.lt(angle)
    fdbk(t,length)
    t.rt(angle)


'''
Functions to draw the letters

t is the turtle used to to draw the letter and the letters are n length
wide and 2n length high

in each of the functions below the turtle returns to the starting position
'''

def draw_a(t,n):
    #Draw A
    diagonal(t,n/2,2*n)
    skip(t,n)
    diagonal(t,-n/2,2*n)
    skipb(t,n)
    disflyline(t,n/4,n/2,n)
    skip(t,n)

def draw_b(t,n):
    #Draw B
    for i in range(2):
        arc2(t,n/2,180)
        t.rt(180)
    fall(t,2*n)
    stump(t,0,2*n)
    skip(t,n)
        
def draw_c(t,n):
    #Draws letter C
    post(t,n)
    fdbk(t,n)
    skip(t,n)

def draw_d(t,n):
    #Draw D
    arc2(t,n,180)
    t.rt(180)
    fall(t,2*n)
    stump(t,0,2*n)
    skip(t,n)

def draw_e(t,n):
    #Draws letter E
    draw_f(t,n)
    skipb(t,n)
    fdbk(t,n)
    skip(t,n)


def draw_f(t,n):
    #Draws letter F
    post(t,n)
    flyline(t,n,n)
    skip(t,n)

def draw_g(t,n):
    #Draws letter G
    post(t,n)
    fdbk(t,n)
    stump(t,n,n)
    disflyline(t,n/2,n/2,n)
    skip(t,n)

def draw_h(t,n):
    #Draws letter H
    stump(t,0,2*n)
    flyline(t,n,n)
    stump(t,n,2*n)
    skip(t,n)

def draw_i(t,n):
    #Draws letter I
    flyline(t,n,2*n)
    stump(t,n/2.0,2*n)
    fdbk(t,n)
    skip(t,n)

def draw_j(t,n):
    #Draw letter J
    arc2(t,n/2,90)
    fd(t,(2*n)-n/2)
    t.rt(90)
    floatlineb(t,n/2,2*n)
    flyline(t,n,2*n)
    skip(t,n)

def draw_k(t,n):
    #Draws K
    stump(t,0,2*n)
    rise(t,n)
    diagonal(t,n,n)
    diagonal(t,n,-n)
    fall(t,n)
    skip(t,n)

def draw_l(t,n):
    #Draws letter L
    stump(t,0,2*n)
    fdbk(t,n)
    skip(t,n)

def draw_m(t,n):
    #Draws letter M
    stump(t,0,2*n)
    draw_v(t,n)
    skipb(t,n)
    stump(t,n,2*n)
    skip(t,n)

def draw_n(t,n):
    #Draws N
    stump(t,0,2*n)
    stump(t,n,2*n)
    rise(t,2*n)
    diagonal(t,n,-2*n)
    fall(t,2*n)
    skip(t,n)

def draw_o(t,n):
    #Draws letter O
    skip(t,n)
    circle3(t,n)
    skipb(t,n)
    skip(t,2*n)

def draw_p(t,n):
    #Draw P
    rise(t,n)
    arc2(t,n/2,180)
    t.rt(180)
    fall(t,2*n)
    stump(t,0,2*n)
    skip(t,n)

def draw_q(t,n):
    #Draw Q
    draw_o(t,n)
    diagonal(t,-n,n)
    
def draw_r(t,n):
    #Draws R
    vline(t,2*n)
    arc2(t,n/2,-180)
    t.rt(180)
    diagonal(t,n,-n)
    fall(t,n)
    skip(t,n)

def draw_s(t,n):
    # Draws S
    fd(t,n/2)
    arc2(t,n/2,180)
    arc2(t,n/2,-180)
    fd(t,n/2)
    gammab(t,n)
    skip(t,n)

def draw_t(t,n):
    #Draws letter T
    flyline(t,n,2*n)
    stump(t,n/2.0,2*n)
    skip(t,n)

def draw_u(t,n):
    #Draws letter U
    stump(t,0,2*n)
    fdbk(t,n)
    stump(t,n,2*n)
    skip(t,n)

def draw_v(t,n):
    #Draws V
    skip(t,n/2)
    diagonal(t,-n/2,2*n)
    diagonal(t,n/2,2*n)
    skipb(t,n/2)
    skip(t,n)

def draw_w(t,n):
    stump(t,0,2*n)
    skip(t,n)
    rise(t,2*n)
    t.lt(180)
    draw_v(t,n)
    skipb(t,n)
    vline(t,2*n)
    t.rt(180)
    


def draw_x(t,n):
    diagonal(t,n,2*n)
    skip(t,n)
    diagonal(t,-n,2*n)
    skipb(t,n)
    skip(t,n)

def draw_y(t,n):
    #Draws Y
    skip(t,n/2)
    vline(t,n)
    diagonal(t,n/2,n)
    diagonal(t,-n/2,n)
    floatlineb(t,n/2,n)
    skip(t,n)

def draw_z(t,n):
    #Draws z
    flyline(t,n,2*n)
    diagonal(t,n,2*n)
    fdbk(t,n)
    skip(t,n)

def draw_(t, n):
    # draw a space
    skip(t, n)


if __name__ == '__main__' :
    
    size = 20
    bob = turtle.Turtle()
    
    for f in [draw_b, draw_a, draw_b, draw_e]:
        f(bob,size)
        skip(bob,size)

    turtle.mainloop()



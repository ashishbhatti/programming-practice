from __future__ import print_function, division

import turtle
import math

from polygon import *

def spoke(t,length,angle):
    '''Draws a line of length n inclides at angle with current direction
    returns at the same spot
    '''
    t.lt(angle)
    t.fd(length)
    t.pu()
    t.bk(length)
    t.rt(angle)
    t.pd()

def pie_lines (t,length,n):
    ''' Draws pizza cuts in a polygon 
    t:turtle,
    n:no of sides of polygon,
    length: length of sides of polygon
    '''
    theta = 360.0/n
    half_int_angle = 90-180.0/n
    pie_length = (length/2)/(math.cos(half_int_angle*2*math.pi/360.0))
    for i in range(n):
        t.pu()
        t.fd(length)
        t.pd()
        spoke(t,pie_length,half_int_angle+theta)
        t.lt(theta)
        
''' Testing the functions

bob = turtle.Turtle()
polygon(bob,100,5)
pie_lines(bob,100,5)
turtle.mainloop()

'''

def draw_pie(t,length,n):
    '''Draws a pie of sides n and size = length
    '''
    polygon(t,length,n)
    pie_lines(t,length,n)

if __name__ == '__main__':
    bob = turtle.Turtle()
    spoke_length = 40
    n=5
    length = 2*spoke_length*math.cos((90-180/n)*2*math.pi/360.0)
    bob.pu()
    bob.bk(3*length)
    bob.pd()
    
    
    for i in range(3):
        half_int_angle = 90-180.0/n
        length = 2*spoke_length*math.cos(half_int_angle*2*math.pi/360.0)
        
        bob.lt(half_int_angle/2)
        draw_pie(bob,length,n)
        bob.rt(half_int_angle/2)
        bob.pu()
        bob.fd(3*length)
        bob.pd()
        n=n+1


    bob.hideturtle()
    turtle.mainloop()

from __future__ import print_function, division

import turtle
import math

from polygon import arc

def petal(t,r,angle):
    ''' Draws a petal using the arc function
    t: turtle, r: radius, angle: angle subtended on the centre
    returns the turtle in initial state
    '''
    for i in range(2):
        arc(t,r,angle)    
        t.lt(180-angle)
    
def flower(t,radius,petals,angle):
    '''Draws flower by using petal
    t:turtle
    radius: radius of flower
    petals: no. of petals
    angle: angle subtended by the arc on the centre
    '''
    half_theta = angle*math.pi/360.0
    r = (radius/2)/math.sin(half_theta) #Radius of flower = 2*(r*math.sin(half_theta))
    for i in range(petals):
        petal(t,r,angle)
        t.lt(360 / petals)

def move (t,length):
    ''' Moves turtle t, length forwards without leaving a train.
    '''
    t.pu()
    t.fd(length)
    t.pd()



if __name__ == '__main__':
    bob = turtle.Turtle()
    
    ''' Test the functions
    #petal(bob,1000,20)
    flower(bob,100,6,90)
    turtle.mainloop()
    '''

    # Draw the figures as drawn in the book
    move(bob,-100)
    flower(bob,100,7,60.0)

    move(bob,200)
    flower(bob,100,10,80.0)

    move(bob,200)
    flower(bob,100,20,20.0)

    bob.hideturtle()
    turtle.mainloop()


    
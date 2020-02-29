import turtle
import math
#bob = turtle.Turtle()
#print(bob)
#turtle.mainloop()

def draw_square(t):
    t.fd(100)
    t.lt(90)
    
    t.fd(100)
    t.lt(90)
    
    t.fd(100)
    t.lt(90)
    
    t.fd(100)

#draw_square(bob)
#turtle.mainloop()

#for i in range(4):
#    print('Hello!')
#
#for i in range(4):
#    bob.fd(100)
#    bob.lt(90)

def square (t,length):
    '''Draws a sqaure using turtle object t
       t ends up in the same position facing the same direction
    '''
    for i in range(4):
        t.fd(length)
        t.lt(90)

def polyline(t, n, length, angle):
    """Draws n line segments.

    t: Turtle object
    n: number of line segments
    length: length of each segment
    angle: degrees between segments
    """
    for i in range(n):
        t.fd(length)
        t.lt(angle)

def polygon (t,length,n):
    '''Draws n sided regular polygon with turtle object t
       t ends in the same position facing same direction
    '''
    angle = 360/n
    for i in range (n):
        t.fd(length)
        t.lt(angle)

def circle(t,r):
    '''Draws circle of radius r 
       from the point where the turtle currently is
    '''
    circum = 2*math.pi*r
    n = int(circum)
    length = circum / n
    polygon (t,length,n)

def circle2(t, r):
    circumference = 2 * math.pi * r
    n = 50
    length = circumference / n
    polygon(t, length,n)

def open_polygon(t,length,n,sides):
    '''Draws an open polygon with no of sides = sides
    '''
    angle = 360/n
    for i in range (sides):
        t.fd(length)
        t.lt(angle)

def circle3(t, r):
    circumference = 2 * math.pi * r
    n = int(circumference / 3) + 3
    length = circumference / n
    polygon(t, length,n)

def arc(t,r,angle):
    '''Draws arc of radius r and angle is subtended on center '''
    circum = 2*math.pi*r
    n = int(circum)
    length = circum / n
    peri = (angle*2*math.pi/360)*r
    sides = int(peri/length)
    open_polygon(t,length,n,sides) 

def arc2(t, r, angle):
    """Draws an arc with the given radius and angle.

    t: Turtle
    r: radius
    angle: angle subtended by the arc, in degrees
    """
    arc_length = 2 * math.pi * r * abs(angle) / 360
    n = int(arc_length / 4) + 3
    step_length = arc_length / n
    step_angle = float(angle) / n

    # making a slight left turn before starting reduces
    # the error caused by the linear approximation of the arc
    t.lt(step_angle/2)
    polyline(t, n, step_length, step_angle)
    t.rt(step_angle/2)


if __name__ == '__main__':
    
    bob = turtle.Turtle()
    alice = turtle.Turtle()
    slon = turtle.Turtle()
    
    #square(bob,50)
    ##polygon(bob,100,6)
    circle(bob,50)
    #arc(bob,50,360)
    circle2(alice,50)
    circle2(slon,50)
    turtle.mainloop()
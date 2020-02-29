import turtle

def koch(t,length):
    if length<3:
        t.fd(length)
        return
    koch(t,length/3)
    t.lt(60)
    koch(t,length/3)
    t.rt(120)
    koch(t,length/3)
    t.lt(60)
    koch(t,length/3)

bob = turtle.Turtle()
for i in range(3):
    koch(bob,200)
    bob.rt(120)
turtle.mainloop()

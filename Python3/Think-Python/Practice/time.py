'''
Finds out the current time in hours, minutes and seconds.
And tells the number of days since the epoch
'''

from __future__ import print_function, division
import time

curr = time.time()

century = 2903040000
decade = 290304000
year = 29030400
day = 86400
hour = 3600
minute = 60
second = 1

for duration in [century, decade, year, day, hour, minute, second]:
    if curr > duration:
        a = curr // duration
        curr = curr - a*duration
        print(a)


#days = curr // day
#
#curr = curr - days*day
#hours = curr//hour
#curr = curr - hours*hour
#minutes = curr // minute
#curr = curr - minute*minutes
#seconds = curr // 1
#
#for i in [days, hours, minutes, seconds]:
#    print(i)



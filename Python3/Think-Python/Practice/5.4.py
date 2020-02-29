'''
Solution to question 5.4
'''

def recurse(n,s):
    '''
    it gives sum of series (s) + n + n-1 + n-2 ....... 1
    '''
    if n == 0:
        print(s)
    else:
        recurse(n-1,n+s)

#recurse(3,0)

'''
stack diagram

__main__   : 
recurse 1  : n = 3, s = 0
recurse 2  : n = 2, s = 3
recurse 3  : n = 1, s = 5
recurse 2  : n = 0, s = 6

'''
#recurse(-1,0)
recurse (10,7)

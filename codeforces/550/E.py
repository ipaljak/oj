#!/usr/bin/python

def main():
    
    n = int(raw_input())
    a = raw_input().split()

    if a[-1] == '1':
        print "NO"
        return

    if len(a) == 1: 
        print "YES\n0"
        return

    if a[-2] == '1':
        print "YES"
        print "->".join(a)
        return

    if '0' not in a[:-2]:
        print "NO"
        return
    else: 
        l = n - a[-3::-1].index('0') - 3
        print "YES"
        if l == 0:
            print '(0->(' + "->".join(a[l + 1:-1]) + '))->0'
        else:
            print "->".join(a[:l]) + '->(0->(' + "->".join(a[l + 1:-1]) + '))->0'

main()

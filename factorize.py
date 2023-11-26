#!/usr/bin/python3
import time

def fact(number):
    global end
    begin = time.time()
    p = 1
    while p < number:
        q = 1
        while q <= (number // 2):
            n = p * q
            if n == number:
                print(p, q)
                end = time.time()
                return end - begin
            else:
                q += 1
        p += 1

number = int(input("Enter the number (n) to factorzie: "))
time_spent = fact(number)
print("time spent: {}".format(time_spent))

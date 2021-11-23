import math
print("Enter 3digit number: ")
number = int(input())
hundreds = math.floor(number/100)
dozens = math.floor(((number / 100 - hundreds) * 10))
ones = round((((number / 100 - hundreds) * 10) - dozens) * 10)
average = (hundreds + dozens + ones) / 3
print("Dozens: "+str(dozens)+"\n")
print("Ones: "+str(ones)+"\n")
print("Average: "+str(average)+"\n")


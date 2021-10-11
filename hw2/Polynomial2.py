from decimal import Decimal

#judge if exp is int or not
def is_int(exp):
    try:
        int(exp)
        return True
    except:
        return False

#judge if input data is float or not
def is_float(value):
    try:
        float(value)
        return True
    except:
        return False

#return the highest power and change the type into int
def highestPower(coff):
    return int(coff[0])

#change the input data into polynomial type and print out
def display(highestPow, coff):
    print("f(x) = ",end = '')
    for i in range(0, highestPow+2):
        if i == 0:
            print(coff[i+1], end = '')
        else:
            if coff[i+1] != 0:
                print(" + ", coff[i+1], end = '')
                for x in range(i, 0, -1):
                    print("*x", end = '')
    print("")

#comput the derivative and print out
def derivative(highestPow, coff, dev_coff):
    if highestPow == 0:
        dev_coff[0] = highestPow
    else:
        dev_coff[0] = highestPow - 1

    for i in range(2, highestPow + 2):
        dev_coff[i-1] = coff[i]*(i-1)

    print("f'(x) = ", end = '')
    for j in range(0, dev_coff[0]+2):
        if j == 0:
            if dev_coff[j+1] != 0 or dev_coff[j] == 0:
                print(dev_coff[j+1], end = '')
        else:
            if dev_coff[j+1] != 0:
                print(" + ", dev_coff[j+1], end = '')
                for y in range(j, 0, -1):
                    print("*x", end = '')
    print("")

#compute the total of the function and return
def compute(highestPow, coff, x):
    global total 
    total= coff[1]
    global tmp 
    tmp = 0
    for k in range(2, highestPow+2):
        tmp = coff[k]
        for j in range(k-1, 0, -1):
            tmp *= x
        total += tmp
    return total

#judge the input mode is legal or not
while 1:
    debug = input("Two mode: if you want to input polynomial data from keyboard, please enter '1'. In contrast, if you want to input polynomial data from file, please enter '0'.\n")

    if debug.isdigit() and (debug == '0' or debug == '1'):
        debug = int(debug)
        break
    else:
        print("Input is not legal.")

#choose what way to get the input data
if debug == 1:
    buf = input("Please enter the polynomial data.\n")
    de_next = 0
elif debug == 0:
    f = open('polydata.txt', 'r')


while 1:
    if debug == 1 and de_next == 1:
        buf = input("Please enter the polynomial data.\n")
    elif debug == 1 and de_next == 0:
        de_next = 1
    elif debug == 0:
        buf = f.readline()
        if len(buf) == 0:
            break

    inp_list = buf.split(" ")
    inp_len = len(inp_list)

#initialization
    num = 0
    flag = 0
    coff = [0]*100
    dev_coff = [0]*100

    x = input("Please enter the 'x' of the polynomial:\n")
    if is_float(x) ==True:
        x = float(x)
    else:
        flag = 1

    #judge of the input polynomial is legal or not.
    if is_int(inp_list[0]) == True:
        coff[num] = float(inp_list[0])
        num += 1
    else:
        flag = 1

    
    for cal in range(1, inp_len):
        if is_float(inp_list[cal]) == False:
            flag = 1
            break
        else:
            coff[num] = float(inp_list[cal])
            num += 1

    if num != (coff[0] + 2):
        flag = 1

    #subroutine
    if flag != 1:
        highestPow = highestPower(coff)
        print("highest:", highestPow, "num:", num)
        display(highestPow, coff)
        derivative(highestPow, coff, dev_coff)
        poly_out = compute(highestPow, coff, x)
        output = Decimal(poly_out)
        print("f(", x, ") = ", round(output, 3))
        poly_dev_out = compute(dev_coff[0], dev_coff, x)
        output_dev = Decimal(poly_dev_out)
        print("f'(", x, ") = ", round(output_dev, 3))
    else:
        print("Input is not legal.")
        
f.close()
print("Complete all calculation.")

def is_float(value):
    try:
        float(value)
        return True
    except:
        return False

def highestPower(coff):
    return int(coff[0])

def display(highestPow, coff):
    print("f(x) = ")
    for i in highestPow:
        if i == 0:
            print(coff[i+1])
        else:
            if coff[i+1] != 0:
                print(" + ", coff[i+1])
                for x in range(i, 1, -1):
                    print("*x")
    print("\n")

def derivative(highestPow, coff, dev_coff):
    if highestPow == 0:
        dev_coff[0] = highestPow
    else:
        dev_coff[0] = highestPow - 1

    for i in range(2, highestPow+1):
        dev_coff[i-1] = coff[i]*(i-1)

    print("f'(x) = ")
    for i in dev_coff[0]:
        if i == 0:
            print(dev_coff[i+1])
        else:
            if dev_coff[i+1] != 0:
                print(" + ", dev_coff[i+1]) 
                for x in range(i, 1, -1):
                    print("*x")

    print("\n")

def compute(highestPow, coff, x):
    total = coff[1]
    tmp = 0
    for i in range(2, highestPow+1):
        tmp = coff[i]
        for j in range(i-1, 1, -1):
            tmp = tmp * x
        total += tmp
    return total


while 1:
    debug = input("The mode: if you want to input polynomial data from keyboard, please enter '1'. In contrast, if you want to input polynomial data from file, please enter '0'.\n")
    #debug = int(debug)

    if debug.isdigit() and (debug == '0' or debug == '1'):
        debug = int(debug)
        break
    else:
        print("Input is not legal.")


if debug == 1:
    buf = input("Please enter the polynomial data.")
    #buf = list(buf)
    #inp_list = buf.spilt(" ")
    de_next = 0
elif debug == 0:
    f = open('polydata.txt', 'r')
    #buf = f.readline()

while True:
    if debug == 1 and de_next == 1:
        buf = input("Please enter the polynomial data.")
        #buf = list(buf)
    elif debug == 1 and de_next == 0:
        de_next = 1
    elif debug == 0:
        buf = f.readline()
        if len(buf) == 0:
            break

    x = input("Please enter the 'x' of the polynomial.")
    x = float(x)

    flag = 0
    buf_len = len(buf)
    word_len = 0
    word = ['\0']*100
    coff = [0]*100
    dev_coff = [0]*100
    num = 0

    inp_list = buf.spilt(" ")
    inp_len = len(inp_list)

    for cal in range(0, inp_len-1):
        if is_float(inp_list[cal]) == False:
            print("Input is not legal.")
            flag = 1
            break
        else:
            coff[num] = float(inp_list[cal])
            num += 1

"""
    for i in range(0, buf_len):
        if buf[i].isdigit or buf[i] == ' ' or buf[i] == '-' or buf[i] == '.' or buf[i] == '\n' or buf[i] == '\0':
            print("test: ",buf[i], "\n")
            if buf[i] == '.' or buf[i].isdigit or buf[i] == '-':
                if buf[i] == '-' and word_len != 0:
                    #print("Input is not legal.11111")
                    for j in range(0, word_len):
                        word[j] = '\0'
                    word_len = 0
                    break;
                word[word_len] = buf[i];
                #print("word_len:", word_len)
                word_len += 1
            elif buf[i] == ' ' or buf[i] == '\n' or buf[i] == '\0':
                coff[num] = float(word)
                #print("num1:", num)
                num += 1
                for j in range(0, word_len):
                    word[j] = '\0'
                word_len = 0
        else:
            print("Input is not legal.222222")
            for j in range(0, word_len):
                word[j] = '\0'
            word_len = 0
            flag = 1
            break
"""
    print("num:",num,"coff:",coff[0],"flag:",flag,"\n")
    if num !=(coff[0] + 2) and flag != 1:
        print("Input is not legal.33333")
        flag = 1

    if flag != 1:
        highestPow = highestPower(coff)
        display(highestPow, coff)
        derivative(highestPow, coff, dev_coff)
        poly_out = compute(highestPow, coff, x)
        print("f(", x, ") = ", poly_out, "\n")
        poly_dev_out = compute(dev_coff[0], dev_coff, x)
        print("f'(", x, ") = ", poly_dev_out, "\n")

    #for i in range(0, buf_len):
       # buf =
    for i in range(0, num):
        coff[i] = 0
        dev_coff[i] = 0
    #num = 0

f.close()
print("Complete all calculation.\n")


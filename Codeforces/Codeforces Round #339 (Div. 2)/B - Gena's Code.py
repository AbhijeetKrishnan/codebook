import re

n = input()
num_list = input().split()
num_zeroes = 0
has_zero = False
got_nb_num = False
for num in num_list:
    if num == "0":
        has_zero = True
    else:
        if not got_nb_num:
            if re.fullmatch('10*', num):
                num_zeroes = num_zeroes + len(num) - 1
            else:
                non_beautiful_num = num
                got_nb_num = True
        else:
            num_zeroes = num_zeroes + len(num) - 1

if has_zero:
    print("0")
else:
    print(non_beautiful_num + "0" * num_zeroes)

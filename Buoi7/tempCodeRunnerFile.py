num_list = [3, 1, -2, -1 ,5 ,4]
k = 2
sub_list = []

for element in num_list:
    sub_list.append(element)

    if len(sub_list) == k:
        print(sub_list)
        del sub_list[0]
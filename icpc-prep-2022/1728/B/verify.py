import itertools

with open("output", "r") as f:

    for line in f.readlines():
        a = line.split(' ')
        x = 0
        int_l = []
        for i in a:
            int_l.append(int(i))
            if x < int(i): 
                x+=int(i)
            else:
                x = 0
        
        x_true = -1
        for perm in itertools.permutations(int_l):
            x_tmp = 0
            for i in perm:
                if x_tmp < i: 
                    x_tmp+=i
                else:
                    x_tmp = 0
            #print("perm: ", perm, x_tmp)

            if(x_tmp > x_true): blau = perm
            x_true = max(x_tmp, x_true)


        print("x = ", x, x_true)
        print("blau: ", blau)
        assert x == x_true

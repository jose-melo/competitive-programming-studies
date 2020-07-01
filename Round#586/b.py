a = [2, 4, 8, 15, 21, 15, 7]

for i in range(len(a)):
	for j in range(len(a)):
		if (i == j):
			print("0 ")
		else:	
			print(a[i]*a[j], end=" ")

	


import math

def hord(x1, x2, func, c=0.01, step = 0):
	step = step + 1
	x3 = x1 - ((x2 - x1) * func(x1)) / (func(x2) - func(x1))
	if math.fabs(x3 - x1) < c:
		print('Шагов:', step);
		return x3
	else:
		return hord(x3, x2, func, c, step)

def newton(x, func, der_func, c = 0.01, step = 0):
	step = step + 1
	ret_x = x - (func(x)/der_func(x))
	if math.fabs(ret_x - x) < c:
		print('Шагов:', step);
		return ret_x
	else:
		return newton(ret_x, func, der_func, c, step)

def simple_iterators(x1, x2, func, c = 0.01):
	step = 0
	while True:
		step = step + 1
		x3 = (x1 + x2)/2
		if func(x1) * func(x3) < 0:
			if math.fabs(x3 - x1) < c:
				print('Шагов:', step);
				return x3
			x2 = x3
		else:
			if math.fabs(x3 - x2) < c:
				print('Шагов:', step);
				return x3
			x1 = x3



if __name__ == "__main__":
	print("tests : ")
	print("x^2 - 2 = 0")
	print("hord: ")
	print("x =", hord(1, 2, func = lambda x: x**2 - 2, c=0.00000001))
	print("Method Newton: ")
	print("x =", newton(2, func = lambda x: x**2 - 2, der_func = lambda x: 2*x, c = 0.00000001))
	print("Method simple iterators")
	print("x =", simple_iterators(1, 2, func = lambda x: x**2 - 2, c=0.00000001))

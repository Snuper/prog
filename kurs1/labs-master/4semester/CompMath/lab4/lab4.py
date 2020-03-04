# Численное интегрирование
import math
    
def trapez_formula(func, a, b, e = 0.01):
    result = 0
    n = 5
    h = (b - a)/n
    quit = False
    while not quit:
        result_buff = result
        x = a + h
        result = 0
        while x <= b:
            result = result + (x - (x - h)) * ((func(x) + func(x - h))/2)
            x = x + h
        if math.fabs(result_buff - result) < e:
            quit = True
        h = h / 2
    return result

if __name__ == "__main__":
    print('Численное интегрирование.')
    print('Формула трапеций:')
    
    print('Результат:', trapez_formula(lambda x: 1/x, 1, 2, 0.000001))
    print('Реальное значение:', (math.log(2) - math.log(1)))

    
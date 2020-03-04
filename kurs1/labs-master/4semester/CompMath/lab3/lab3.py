import math

# Итерполяция (формула Лагранжа)
def interpolationLagrange(x, points):
    y = 0
    for x_point_i in points:
        points_j = points.copy()
        points_j.pop(x_point_i)
        l = 1
        for x_point_j in points_j:
            l = l * ((x - x_point_j) / (x_point_i - x_point_j))
        y = y + points[x_point_i] * l
    return y
        
# интерполяция (схема Эйткена)
def interpolationAitken(x, dict_points):
    points = getListPoints(dict_points)
    out = []
    result, out = recurAitken(x, points, out)
    for i in range(len(out)*2):
        if i >= len(out):
            r_j = (len(out) - 1) - (i - (len(out) - 1))
        else:
            r_j = i
        str_out = ''
        for j in range(r_j + 1):
            if i%2 == j%2:
                str_out += ' | ' + str(out[j][int((i-j)/2)]) + (8 - len(str(out[j][int((i-j)/2)]))) * ' '
            else:
                str_out += ' | ' + ' ' * 8
        print(str_out)

    return result

def recurAitken(x, points, arrayOut):
    if len(points) == 1:
        result = round(points[0]['y'], 4)

        if len(arrayOut) == 0:
            arrayOut.append([])
            arrayOut[0].append(result)
            # print(len(points) * ' | ' + str(result))
        else:
            if arrayOut[0].count(result) == 0:
                arrayOut[0].append(result)
                # print(len(points) * ' | ' + str(result)

        return result, arrayOut
    else:
        a1, arrayOut = recurAitken(x, points[1:], arrayOut)
        a2, arrayOut = recurAitken(x, points[:-1], arrayOut)
        result = round((1 / (points[-1]['x'] - points[0]['x'])) * (a1 * (x - points[0]['x']) - a2 * (x - points[-1]['x'])), 4)

        if len(arrayOut) < len(points):
            arrayOut.append([])
            arrayOut[len(points)-1].append(result)
            # print(len(points) * ' | ' + str(result))
        else:
            if arrayOut[len(points)-1].count(result) == 0:
                arrayOut[len(points)-1].append(result)
                # print(len(points) * ' | ' + str(result))

        return result, arrayOut

def getListPoints(dict_points):
    list_points = []
    for x in dict_points:
        list_points.append({'x' : x, 'y' : dict_points[x]})
    return list_points

# интерполяция (формуля Ньютона)
def interpolationNewton(x, dict_points):
    points = getListPoints(dict_points)
    h = 0.5
    P = 0
    for i in range(len(points)):
        Q = 1
        q = (x - points[0]['x']) / h
        for j in range(i):
            Q = Q * (q + j)
        P = P + (difference(i, 0, points) / math.factorial(i)) * Q
    return P


def difference(m, k, points):
    if m == 0:
        return points[k]['y']
    else:
        return difference(m-1, k+1, points) - difference(m-1, k, points)

if __name__ == "__main__":
    x = 2.7
    points = {
        2: math.sin(2),
        2.5: math.sin(2.5),
        3: math.sin(3),
        3.5: math.sin(3.5)
    }
    print(points)
    print('x =', x)
    print("формула Лагранжа:")
    print("interpolation:", interpolationLagrange(x, points))
    print("real: ", math.sin(x))

    print("\nСхема Эйткена:")
    print("interpolation:", interpolationAitken(x, points))
    print("real: ", math.sin(x))

    print("\nФормула Ньютона:")
    print("interpolation:", interpolationNewton(x, points))
    print("real: ", math.sin(x))

    # func_test = lambda x: 2*x**3 - 2*x**2 + 3*x - 1
    # points_test = {
    #     0: func_test(0),
    #     1: func_test(1),
    #     2: func_test(2),
    #     3: func_test(3),
    #     4: func_test(4),
    #     5: func_test(5)
    # }
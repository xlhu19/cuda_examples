
import copy
import random

def builtin_getattr():
    """
    getattr(object, name[, default]) -> value

    Get a named attribute from an object; getattr(x, 'y') is equivalent to x.y.
    When a default argument is given, it is returned when the attribute doesn't
    exist; without it, an exception is raised in that case.
    """
    return

def builtin_zip():
    x = [1, 2, 3]
    y = [4, 5, 6]
    z = [7, 8, 9]
    zip_xyz = zip(x, y, z)
    print(*zip_xyz)

def builtin_map():
    map_r = map(lambda x: x**2, [1, 2, 3, 4, 5])
    print(*map_r)

def builtin_copy():
    a = [1, 2, 3, 4, ['a', 'b']]
    b = a
    c = copy.copy(a)
    d = copy.deepcopy(a)
    a.append(5)
    a[4].append('c')
    print('a = ' + str(a))
    print('b = ' + str(b))
    print('c = ' + str(c))
    print('d = ' + str(d))

def builtin_random():
    rm = random.randint(1000, 9999)
    

if __name__ == "__main__":
    builtin_zip()
    builtin_map()
    builtin_copy()

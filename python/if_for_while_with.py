

def base_for():
#    for iterating_var in sequence:
#        statements(s)

    for letter in 'Python':
        print('Current Letter: ' + letter)

    fruits = ['banana', 'apple', 'mango']
    for fruit in fruits:
        print('Current fruit: ' + fruit)

    for index in range(len(fruits)):
        print('Current fruit: ' + fruits[index])

    for ii in range(0, 10): # 0<=ii<10
        print('Circl ' + str(ii))

def base_args_kwargs():
    def foo(*args, **kwargs):
        print('args = ' + str(args))
        print('kwargs = ' + str(kwargs))
        print('---------------------------------------')

    foo(1, 2, 3, 4)
    foo(a=1, b=2, c=3)
    foo(1, 2, 3, 4, a=1, b=2, c=3)
    foo('a', 1, None, a=1, b='2', c=3)

@staticmethod
def base_at():
    pass

def test_if_1():
    a=5
    b=6
    c = a if a>b else b
    print(c)

def test_if_2():
    a=5
    b=6
    c = [b,a][a>b]
    print(c)

"""
    [operate(x) for x in xxx if condition]
    [operate(x,y) for x in xxx for y in yyy if condition]
"""
def test_for():
    x=[1,2,3,4]
    y=[5,6,7,8]
    z=[a+b for a in x for b in y if a%2 == 0 and b%2 ==0]
    print(z)

    # from 10 to 19
    for num in range(10,20):
        print(num)

def test_with():
    pass
"""
=== Format:
    with context_expression [as target(s)]:
        with-body

=== Process:
    context_manager = context_expression
    exit = type(context_manager).__exit__
    value = type(context_manager).__enter__(context_manager)
    exc = True # True means run normally, and will ignore any exceptions; False means raise exception
    try:
        try:
            target = value  # if use as
            with-body     # execute with-body
        except:
            # there are some exceptions
            exc = False
            # if __exit__ returns True, ignore exception if returns False, raise exception
            # handle exception by upper code
            if not exit(context_manager, *sys.exc_info()):
                raise
    finally:
        # exit normally or through statement-body's break/continue/return
        if exc:
            exit(context_manager, None, None, None) 
        # default return None, None is treated as False if boolean context
"""

"""
  lambda define anonymous function
"""
def test_lambda():
    p = lambda x:x+1
    print p(1)

    m = lambda x,y,z: (x-y)*z
    print(m(3,1,2))

if __name__ == "__main__":
    # test_if_1()
    test_if_2()
    test_for()
    test_lambda()


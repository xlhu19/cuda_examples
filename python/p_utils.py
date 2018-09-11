# 1. Use def to define a function.
# 2. It is not necessary to specify the return type and argument type.
# 3. If no return, the return value is NONE.
# 4. All the functions should be defined before using them.
def sayHello():
    str = "hello"
    print(str)

class TestClass():
    def __init__(self, *args, **kwargs):
        pass

def instanceOfClass():
    b = TestClass()
    print(type(b))

def testAll():
    if 'FC' == u'FC':
        print('Equal')

# or will return the first true value
def test_or():
    a = None or 10
    print(a)

if __name__ == "__main__":
    print('This is main of module "hello.py"')
    sayHello()
    instanceOfClass()
    testAll()


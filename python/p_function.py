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

# If use "python hello.py" to execute this module directly,
# the __name__ equals to "__main__".
# If this module is used by other modules, the __name__
# will be the module name.
if __name__ == "__main__":
    print('This is main of module "hello.py"')
    sayHello()
    instanceOfClass()
    testAll()

    a = 11 or 10
    print(a)


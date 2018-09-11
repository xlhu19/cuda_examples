def de(f):
    def _call_():
        print('-------------------------------')
        return f()
    return _call_

@de
def func1():
    print('I am func 1.')

"""
@de
def func1():
equals to func1=de(func1)
"""

if __name__ == "__main__":
    func1()


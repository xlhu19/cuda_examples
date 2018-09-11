

def func_01():
    print("func_01")
    raise Exception("func_01 exception")

def func_02():
    print("func_02")
    func_01()
    print("func_02 continue")

def func_03():
    print("func_03")
    try:
        func_02()
    except Exception:
        print("func_02 exception")

def func_04():
    print("func_04")
    try:
        func_01()
    finally:
        print("func_04 finally")

def func_05():
    print("func_05")
    try:
        func_04()
    except Exception:
        print("func_05 exception")

if __name__ == "__main__":
    func_05()

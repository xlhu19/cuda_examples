#coding:utf-8

class class01:
    # var1 是类变量，可以用class01.var1 访问
    var1 = ''

    # 实例化的时候，调用 __init__
    # self 表示 instance, 每个成员函数必有参数，可以是其他字符串
    def __init__(self, val):
        self.var1 = val

if __name__ == "__main__":
    # 创建对象
    inst = class01(3)
    print(inst.var1)
    print(class01('123').var1)
    inst.var2 = 7  # 添加一个 'var2' 属性
    inst.var2 = 8  # 修改 'var2' 属性
    print(inst.var2)
    del inst.var2  # 删除 'var2' 属性

    print(hasattr(inst, 'var3'))    # 如果存在属性返回 True。
    print(getattr(inst, 'var1'))    # 返回属性的值
    setattr(inst, 'var3', 8) # 添加属性值为 8
    delattr(inst, 'var3')    # 删除属性
    
    # 内置属性
    # __dict__ : 类的属性（包含一个字典，由类的数据属性组成）
    # __doc__ :类的文档字符串
    # __name__: 类名
    # __module__: 类定义所在的模块（类的全名是'__main__.className'，如果类位于一个导入模块mymod中，那么className.__module__ 等于 mymod）
    # __bases__ : 类的所有父类构成元素（包含了一个由所有父类组成的元组）

    # __del__在对象销毁的时候被调用，当对象不再被使用时，__del__方法运行

class class02:
    def __init__(self, val):
        self.var1 = val

# Inherit
# 1. Multiple inherit
# 2. 
class subclass(class01, class02):
    def __init__(self):
        print("subclass init")


if __name__ == "__main__":
    inst1 = subclass()


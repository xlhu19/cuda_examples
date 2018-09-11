#!/usr/bin/python

import dis

def foo(x):
  def funcs(y):
    print(x)
  return funcs

code_obj = compile('sum([1,2,3])',  '', 'single')
dis.dis(code_obj)

print(foo.func_code)
dis.dis(foo.func_code)

bar=foo("x")
print(bar.__closure__)
print(bar.__closure__[0].cell_contents)


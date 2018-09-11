
a=set('boy')
b=set(['y', 'b', 'o','o'])
c=set({"k1":'v1','k2':'v2'})
d={'k1','k2','k2'}
e={('k1', 'k2','k2')}
print(a,type(a))
print(b,type(b))
print(c,type(c))
print(d,type(d))
print(e,type(e))

# OUTPUT:
# {'o', 'b', 'y'} <class 'set'>
# {'o', 'b', 'y'} <class 'set'>
# {'k1', 'k2'} <class 'set'>
# {'k1', 'k2'} <class 'set'>
# {('k1', 'k2', 'k2')} <class 'set'>


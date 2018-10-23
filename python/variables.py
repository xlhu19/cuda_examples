# All variable related definitions and operations in this file.
# Python has 5 standard types:
# 1. Number
# 2. String
# 3. List
# 4. Tuple (read only)
# 5. Dictionary

class vcommon:
    def vprint(self):
        print("----- %s -----" % (self.__class__.__name__))
        
# Variable Basic
class python_variable:
    def definition(self):
        var0 = 1
        # multiple variables definition
        var1 = var2 = var3 = 1
        var4, var5, var6 = 1, 2, 'string'

    def operation(self):
        var0 = 100
        var1 = 100.0
        var2 = 19871128
        del var0
        del var1, var2

# Number
class python_number(vcommon):
    def __init__(self):
        self.vprint()

    def definition(self):
        # int (python3 has only int, no long int)
        var_a0 = 100
        var_a1 = 0x2600

        # float
        var_b0 = 100.0

        # bool
        var_c0 = True # real value is 1, will be treated as number
        var_c1 = False # real value is 0, will be treated as number

        # complex
        var_d0 = 3.14j
        var_d1 = 9.322e-36j
        var_d2 = -.6545+0j
        var_d3 = .876j
        var_d4 = 45.j
        var_d4 = complex(4,5)

    def operation(self):
        var_a0 = 100 # create an object when define
        var_a0 = 200 # value can not be changed, so this will create another object
        
        c0 = var_a0 + 12
        c1 = var_a0 - 12
        c2 = var_a0 * 12
        c3 = var_a0 / 12 # a float
        c4 = var_a0 // 12 # an int
        c5 = var_a0 % 12
        c6 = var_a0 ** 2
        print("var_a0 + 12 = " + str(c0))
        print("var_a0 - 12 = " + str(c1))
        print("var_a0 * 12 = " + str(c2))
        print("var_a0 / 12 = " + str(c3))
        print("var_a0 // 12 = " + str(c4))
        print("var_a0 % 12 = " + str(c5))
        print("var_a0 ** 2 = " + str(c6))

# String
class python_string(vcommon):
    def __init__(self):
        self.vprint()

    def definition(self):
        s0 = ''
        s1 = 'string'
        s2 = "string"
        s3 = """'string
    format'"""
        s4 = '''"string
    format"'''
        s5 = "spam's"
        s6 = 'spam"s'
        s7 = 's\np\tam'
        s8 = ('123'
          '456')
        s9 = ("123"
          "456")
        s10 = r'c:\\dir\test.txt' # raw string
        s11 = b'12345' # in python 3.0
        s12 = u'12345' # only in python 2.6
        print(s3)
        print(s4)
        print(s5)
        print(s6)
        print(s7)
        print(s8)
        print(s9)
        print(s10)
        print(s11)
        print(s12)

    def operation(self):
        var_a0 = 'HelloWorld!'
        var_a1 = var_a0 + 'Ni hao!'
        print("var_a0 is : " + var_a0)
        print("var_a0[0] is : " + var_a0[0])
        print("var_a0[-1] is : " + var_a0[-1])
        print("var_a0[2:5] is : " + var_a0[2:5]) # [2,5)
        print("var_a0[2:] is : " + var_a0[2:])
        print("var_a0*2 is : " + var_a0 * 2)
        print("var_a1 is : " + var_a1)
        print("var_a1 length is : " + str(len(var_a1)))

    def string_formatting(self):
        print("-------------------")
        
        print('a %s parrot' % 1.2)
        print('a %s %s %s parrot' % (1.2, 2.3, ['one', 'two']))
        print('a %(t1)s %(t2)s parrot' % {'t1': 'this is t1', 't2': 'this is t2'})

    def string_replace(self):
        text = "Time is lost."
        print(text.replace("is", "was"))

    def string_split(self):
        print("-------------------")

        string1 = "str1,str2,str3"
        strlist1 = string1.split(',')
        print(string1)
        print(strlist1)

    def string_splitlines(self):
        print("-------------------")

        string1 = "line1\r\nline2\r\nline3"
        strlist1 = string1.splitlines()
        print(string1)
        print(strlist1)

    """
      strip the begin and end characters of a string
      default strip space.
    """
    def string_strip(self):
        print("-------------------")
        string1 = "   abcdefg   "
        string2 = "!!!abcdefg!!!"
        print(string1.strip())
        print(string2.strip('!'))

    def string_endswith(self):
        string1 = 'abcdefg'
        if string1.endswith('g'):
            print("endswith g")

        if not string1.endswith('\n'):
            print("not endswith \\n")

    def is_unicode(self):
        text1 = u'1234'
        # if isinstance(text1, unicode):
            # print('is unicode')
        # else:
            # print('is not unicode')

        text2 = '1234'
        if isinstance(text2, str):
            print('is string')
        else:
            print('is not string')

    def _test(self):
        vdisk_name = 'vdisk12'
        vdisk_attributes = None
        print('leave: _is_vdisk_defined: vdisk %(vol)s with %(str)s '
              % {'vol': vdisk_name, 'str': vdisk_attributes is not None})

# List
class python_list(vcommon):
    def __init__(self):
        self.vprint()
        print("----- %s -----" % (self.__class__.__name__))

    def definition(self):
        l0 = ['abcd', 786, 2.23, 'john', 70.2]
        print(l0)
        l1 = list((1,3,5,7,9)) # Change tuple to list
        print(l1)

    def operation(self):
        var_a0 = ['abcd', 786, 2.23, 'john', 70.2]
        var_a1 = ['start', 12]
        var_a2 = var_a0 + var_a1
        print("=== list operation result ===")
        print("var_a0: " + str(var_a0))
        print("var_a0[0]: " + str(var_a0[0]))
        print("var_a0[1:3]: " + str(var_a0[1:3]))
        print("var_a0[2:]: " + str(var_a0[2:]))
        print("var_a0*2: " + str(var_a0 * 2))
        print("var_a2: " + str(var_a2))

        for element in var_a2:
            print(element)

        print(type(var_a0))

        """
        L.append(var)
        L.insert(index,var)
        L.pop(var)
        L.remove(var)
        L.count(var)
        L.index(var)
        L.extend(list)
        L.sort()
        L.reverse()
        """


from collections import namedtuple
class python_tuple(vcommon):
    def __init__(self):
        self.vprint()
        print("----- %s -----" % (self.__class__.__name__))

    def definition(self):
        t0 = ('abcd', 786 , 2.23, 'john', 70.2)
        print(t0)

    def operation(self):
        var_h0 = ('abcd', 786 , 2.23, 'john', 70.2)
        var_h1 = ('start', 12)
        var_h2 = var_h0 + var_h1
        print("var_h0: " + str(var_h0))
        print("var_h0[0]: " + str(var_h0[0]))
        print("var_h0[1:3]: " + str(var_h0[1:3]))
        print("var_h0[2:]: " + str(var_h0[2:]))
        print("var_h0*2: " + str(var_h0 * 2))
        print("var_h2: " + str(var_h2))

        Person = namedtuple('Person', 'name age gender')
        print(type(Person))

        Bob = Person(name='Bob', age='30', gender='male')
        Jane = Person(name='Jane', age='29', gender='female')
        print(Bob)
        print(Jane.name)

# Dictionary
class python_dictionary(vcommon):
    def __init__(self):
        self.vprint()

    def definition(self):
        # key can be number, string, tuple, because key is not changeable
        d1 = {}
        d3 = {'a':None, 'b':None}
        d5 = {'a':'1', 'b':'2'}
        d6 = dict(a="1", b="2")
        d2 = dict.fromkeys(['a', 'b'])
        d4 = dict(zip(["a","b"], ["1","2"]))

    def dic_has_key(self):
        d2 = {'a':'1', 'b':'2'}
        # only in python 2
        # if d2.has_key('a'):
        #     print(d2['a'])
        if 'b' in d2:
            print(d2['b'])

    def operation(self):
        print("----- dictionary operation -----")

        var_i5 = {'a':'1', 'b':'2'}
        print(var_i5['a'])

        if 'c' in var_i5:
            print('key c exist')
        else:
            print('key c not exist')

        """
        dict.get(key, default=None)
            if key does not exist, return default value.
        """
        dict1 = {'var1': 1, 'var2': 2, 'var3': 3}

        # dict2 = {key : value for key, value in dict1 if key != 1}

        print(str(dict1))
        # print(str(dict2))

        print('----- Add new keys -----')
        var_i5['c'] = '3'
        print(var_i5['c'])


        # list all
        for k in dict1:
            print(dict1[k])

        for k in dict1.keys():
            print(dict1[k])

        for v in  dict1.values():
            print(v)
        
        for kv in dict1.items():
            print(kv)

        for k,v in dict1.items():
            print(k)

        # sort_dict1 = sorted(dict1.iteritems(), key = lambda asd:asd[1], reverse=True) # sort by value

class python_type_change(vcommon):
    def __init__(self):
        self.vprint()
    def operation(self):
        x = '15'
        y = 20
        print(type(int(x)))
        print(int(x))
        print(float(x))
        print(str(y))
        print(hex(y))
        print(oct(y))

        #repr(x )              
        #eval(str )
        #tuple(s )             
        #list(s )              
        #chr(x )               
        #unichr(x )            
        #ord(x )

if __name__ == "__main__":
    python_variable().definition()
    python_variable().operation()

    # Number
    pnumber = python_number()
    pnumber.definition()
    pnumber.operation()

    # String
    pstring = python_string()
    pstring.definition()
    pstring.operation()
    pstring.string_strip()

    # Tuple
    ptuple = python_tuple()
    ptuple.definition()
    ptuple.operation()

    # List
    plist= python_list()
    plist.definition()
    plist.operation()

    # Dictionary
    pdict = python_dictionary()
    pdict.definition()
    pdict.operation()
    pdict.dic_has_key()

    # Type
    ptype = python_type_change()
    ptype.operation()


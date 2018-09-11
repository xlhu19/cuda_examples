import binascii

s = 'abcde'
# string to hex
h1 = binascii.b2a_hex(s)
h2 = binascii.hexlify(s)

print(h1)
print(h2)

s1 = binascii.a2b_hex(h1)
s2 = binascii.unhexlify(h2)

print(s1)
print(s2)

import re

input = 'heello world'
output = re.sub('hee', 'he', input)
print(output)

pattern = re.compile(r'hello')
match = pattern.match('hello world!')
if match:
   print(match.group())

value = re.compile(r'^[0-9]+$')

result = value.match(float_number)

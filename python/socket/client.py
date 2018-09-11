import socket

address = ('47.88.52.183', 19400)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(address)

data = s.recv(512)
print 'the data received is',data

s.send('hihi')

s.close()

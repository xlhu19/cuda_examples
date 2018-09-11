import smtplib

fromaddr = "qmdjnz@ooe.com"
toaddrs  = "xlhu@cn.ibm.com"
print("Enter message, end with ^D (Unix) or ^Z (Windows):")

# Add the From: and To: headers at the start!
msg = ("From: %s\r\nTo: %s\r\n\r\n"
       % (fromaddr, toaddrs))
msg = msg + "Hello, this is a fake email for test."

print("Message length is", len(msg))

server = smtplib.SMTP('localhost')
server.set_debuglevel(1)
server.sendmail(fromaddr, toaddrs, msg)
server.quit()


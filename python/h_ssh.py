#!/usr/bin/python
import paramiko

def ssh2(ip, username, passwd, cmd):
    try:
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        ssh.connect(ip, 22, username, passwd, timeout=30)
        #for m in cmd:
        stdin, stdout, stderr = ssh.exec_command(cmd)
        out = stdout.readlines()
        for o in out:
            print o,
        print '%s\tOK\n'%(ip)
        ssh.close()
    except :
        print '%s\tError\n'%(ip)

if __name__ == "__main__":
    ssh2('9.19.149.30', 'superuser', 'passw0rd', 'lsadminlun')

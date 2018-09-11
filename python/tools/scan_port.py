import socket
import re
from optparse import OptionParser

common_port = (21,22,23,25,80,81,88,135,137,139,443,445,500,873,1433,1502,1521,2601,2604,3000,3030,3128,3306,3389,4440,6082,6379,7001,7002,7003,7004,7005,8010,8011,8080,8082,8088,8099,8888,9015,9200,11211,27017,28017)
common_port = list(common_port)
socket.getaddrinfo('localhost', 8080)

#check the common ports of the ip
def check_port(ip):
    for port in common_port:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.settimeout(1)
        try:
            result = s.connect_ex((ip, port))
        except:
            s.close()
            return False
        if result == 0:
            print("IP:" + ip + ' Port:' + str(port))
        s.close()

#check the format of a ip
def check_ip_format(ip):
    ip = ip[:-1]
    return ip

def scanportthreadpool(list_tmp):
    pass

def scan_by_threads(ip_list):
    print("************************")
    print("now scanning:")
    for ip in ip_list:
        print(ip)
    print("************************")
    print("the ports the project scanned:")
    print(common_port)
    print("************************")
    print("begin:")
    print(ip_list)
    scanportthreadpool(ip_list)

#check the common port of every ip from the file
def deal_file(file):
    list_tmp = []
    f = open(file,"r")
    ip_list = f.readlines()
    f.close()
    line = 1
    for ip in ip_list:
        if line < len(ip_list):
            ip = check_ip_format(ip)
            list_tmp.append(ip)
            line += 1
        elif line == len(ip_list):
            list_tmp.append(ip)
    scan_by_threads(list_tmp)

def deal_ip_segment(ip_segment):
    index = ip_segment.index('-')
    ip_first = ip_segment[:index]
    ip_last = ip_segment[(index + 1):]
    single_ip_first_num = ip_first.split('.')
    single_ip_last_num = ip_last.split('.')
    ip_top_three = ''
    ip_top_three = ip_top_three.join(single_ip_first_num[i] + '.' for i in range(2))
    ip_top_three = ip_top_three + single_ip_first_num[2]
    #print ip_top_three
    single_ip_first_num = single_ip_first_num[3]
    single_ip_last_num = single_ip_last_num[3]
    #print single_ip_first_num
    #print single_ip_last_num
    ip_list = []
    for i in range(int(single_ip_first_num),int(single_ip_last_num) + 1):
        ip = ip_top_three + '.' + str(i)
        ip_list.append(ip)
    scan_by_threads(ip_list)
    #print 
    #ip_top_three = ip_segment


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option("-t","--target",dest="TARGET",help="write single target")
    parser.add_option("-f","--file",dest="FILE",help="write the file of ip")
    parser.add_option("-c","--ip_segment",dest="IP_SEGMENT",help="write ip segment")
    (options, args) = parser.parse_args()

    ip = options.TARGET
    file = options.FILE
    ip_segment = options.IP_SEGMENT
    if ip != None:
        print("************************")
        print("now scanning:")
        print(ip)
        print("************************")
        print("the ports the project scanned:")
        print(common_port)
        print("************************")
        print("begin:")
        check_port(ip)
    elif file != None:
        deal_file(file)
    elif ip_segment != None:
        deal_ip_segment(ip_segment)


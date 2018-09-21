#!/usr/bin/python3
import sys

src_file = "./linux/linux_command_x.txt"

def get_cmd_text(cmd):
    cmd_start = "### " + cmd
    cmd_end = "### "

    with open(src_file, 'r') as f:
        lines = f.readlines()
        flag = False
        even = True
        color = False

        for l in lines:
            line = l.strip().strip("\n")

            if line.startswith(cmd_start):
                flag = not flag
                continue

            if flag == True:
                if line == "":
                    color = not color
                    even = not even
                if line.startswith(cmd_end):
                    break
                if even == True:
                    if color:
                        print("\033[1;34;40m " + line + " \033[0m")
                    else:
                        print("\033[1;35;40m " + line + " \033[0m")
                else:
                    print("    " + line)

                even = not even

if __name__ == "__main__":
    cmd = sys.argv[1]
    get_cmd_text(cmd)


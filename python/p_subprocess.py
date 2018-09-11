import subprocess

def run_cmd(cmd):
    child = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    child.wait()
    (out, err) = child.communicate()
    if child.returncode == 0:
        return out
    else:
        return err

if __name__ == "__main__":
    print(run_cmd("ls -l"))


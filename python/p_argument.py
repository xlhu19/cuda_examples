# All argument related operations in this file.
import sys
import argparse

def base_args_kwargs():
    def foo(*args, **kwargs):
        print('---------------------------------------')
        print('args = ' + str(args))
        print('kwargs = ' + str(kwargs))

    foo(1, 2, 3, 4)
    foo(a=1, b=2, c=3)
    foo(1, 2, 3, 4, a=1, b=2, c=3)
    foo('a', 1, None, a=1, b='2', c=3)

if __name__ == "__main__":
    # sys.argv is a list which includes all the command line arguments
    # argv[0] is script, argv[1:] is the argument
    print(sys.argv)

    # If want to process complicated arguments, use module argparse
    parser = argparse.ArgumentParser(description="An example to use argparse")
    # Define your own argument
    # Add a new argument "echo", directly use it without - or --
    parser.add_argument("echo")

    # Add a new argument which is optional
    parser.add_argument("-a", "--add", help="add something") # must follow with a value
    parser.add_argument("-p", "--print", action="store_true", help="print something") # no need to follow a value
    parser.add_argument("-s", "--sub", type=int, help="sub something") # type is int
    parser.add_argument("-m", "--mul", type=int, choices=[0, 1, 2], help="multiple something") # type is int and in choices
    parser.add_argument("-d", "--div", type=int, choices=[1, 2, 3], help="division something", default=1) # default is 1

    # Add exclusive argument
    group = parser.add_mutually_exclusive_group()
    group.add_argument("-v", "--verbose", action="store_true")
    group.add_argument("-q", "--quiet", action="store_true")

    args = parser.parse_args()
    print(args.echo)

    # function argument test
    base_args_kwargs()


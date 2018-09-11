def base_for():
    fruits = [dict(name='banana'), dict(name='apple'), dict(name='mango')]
    for fruit in fruits:
        print(str(fruit))
        print('Current fruit: ' + fruit.name)

if __name__ == "__main__":
    base_for()


import random

def test_basic_funcs():
    print(random.random())       # float [0.0, 1.0)
    print(random.uniform(2, 3))  # float [2.0, 3.0]
    print(random.randint(1, 10)) # int [1, 10]

    # random.triangular(low, high, mode)
    # random.betavariate(alpha, beta)
    # random.expovariate(lambd)
    # random.gammavariate(alpha, beta)
    # random.gauss(mu, sigma)
    # random.lognormvariate(mu, sigma)
    # random.normalvariate(mu, sigma)
    # random.vonmisesvariate(mu, kappa)
    # random.paretovariate(alpha)
    # random.weibullvariate(alpha, beta)

def random_int(start, end, num):
    ret = []
    for i in range(1, num + 1):
        ret.append(random.randint(start, end))
    return ret


if __name__ == "__main__":
    test_basic_funcs()
    print(random_int(1, 10, 100))


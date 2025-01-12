# Expression for OPT(n)
# OPT(n) = 1 + min(OPN(n-c)) with c as the denomination of the coin
import numpy as np

def get_OPT(coins, amt):
    OPT = [np.inf] * (amt+1)
    OPT[0] = 0
    for i in range(1, amt+1):
        for c in coins:
            if c <= i:
                OPT[i] = min(OPT[i], 1+OPT[i-c])
    return OPT

def make_change(coins, amt):
    change = []
    OPT = get_OPT(coins, amt)
    count = 0
    tot = OPT[amt]
    while(count < tot):
        OPT_arr = []
        for c in coins:
            OPT_arr.append((c, 1+OPT[amt-c]))
        OPT_min = np.inf
        coin = 0
        for i in range(len(OPT_arr)):
            if OPT_arr[i][1] < OPT_min:
                OPT_min = OPT_arr[i][1]
                coin = OPT_arr[i][0]
        change.append(coin)
        count += 1
        amt -= coin
    return change


coins = [1, 4, 5]
amt = 100
print(get_OPT(coins, amt))
print(make_change(coins, amt))
            
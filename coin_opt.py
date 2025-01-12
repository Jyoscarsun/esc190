import numpy as np

def get_OPT(coins, amt):
    OPT = [np.inf] * (amt+1)
    OPT[0] = 0
    for i in range(i, amt+1):
        for c in coins:
            if c < i:
                OPT[i] = min(OPT[i], 1+OPT[i-c])
    return OPT

def make_change(coins, amt):
    change = []
    OPT = get_OPT(coins, amt)
    tot = OPT[amt+1]
    count = 0
    while(count < tot):
        coin = 0
        OPT_arr = []
        for c in coins:
            OPT_arr.append(c, 1+OPT[amt-c])
        OPT_min = np.inf
        for i in range(len(OPT_arr)):
            if OPT_arr[i][1] < OPT_min:
                OPT_min = OPT_arr[i][1]
                coin = OPT_arr[i][0]
        change.append(coin)
        count += 1
        amt -= c
    return change
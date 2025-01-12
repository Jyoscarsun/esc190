def binary_search_deluxe(L, target):
    low = -1
    high = -1
    left = 0
    right = len(L) - 1
    # Find low
    while left <= right:
        mid = (left + right) // 2
        if L[mid] == target:
            if mid-1 >= 0 and L[mid-1] == target:
                right = mid - 1
            else:
                low = mid
                break
        elif L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    # Find high
    while left <= right:
        mid = (left + right) // 2
        if L[mid] == target:
            if mid+1 < len(L) and L[mid+1] == target:
                left = mid + 1
            else:
                high = mid
                break
        elif L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return [low, high]

L = [1, 2, 3, 10, 10, 10, 12, 12]
target = 12
print(binary_search_deluxe(L, target))
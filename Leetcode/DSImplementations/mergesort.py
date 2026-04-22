def mergesort(nums: list[int], l: int, r: int):
    if l >= r:
        return

    mid = (l + r) // 2

    mergesort(nums, l, mid)
    mergesort(nums, mid + 1, r)

    merge(nums, l, mid, r)


def merge(nums: list[int], l: int, mid: int, r: int):
    leftlist = nums[l:mid + 1]
    rightlist = nums[mid + 1:r + 1]

    i = j = 0
    k = l

    while i < len(leftlist) and j < len(rightlist):
        if leftlist[i] <= rightlist[j]:
            nums[k] = leftlist[i]
            i += 1
        else:
            nums[k] = rightlist[j]
            j += 1
        k += 1

    while i < len(leftlist):
        nums[k] = leftlist[i]
        i += 1
        k += 1

    while j < len(rightlist):
        nums[k] = rightlist[j]
        j += 1
        k += 1


def main():
    nums = [5, 2, 9, 1, 6, 3]

    print("Before:", nums)

    mergesort(nums, 0, len(nums) - 1)

    print("After:", nums)


if __name__ == "__main__":
    main()
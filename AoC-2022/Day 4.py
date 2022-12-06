import re

PAT = r'(\d+)-(\d+),(\d+)-(\d+)'

def is_fully_overlapping(l1: int, r1: int, l2: int, r2: int) -> bool:
    return (l1 <= l2 and r1 >= r2) or (l2 <= l1 and r2 >= r1)

def is_overlapping(l1: int, r1: int, l2: int, r2: int) -> bool:
    return (l1 <= r2 <= r1) or (l2 <= r1 <= r2)

if __name__ == '__main__':
    INPUT_FILE = 'Day 4-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read().splitlines()
    ranges = [tuple(map(int, re.fullmatch(PAT, line).groups())) for line in input]
    full_overlaps = sum([1 for _range in ranges if is_fully_overlapping(*_range)])
    print(full_overlaps)
    overlaps = sum([1 for _range in ranges if is_overlapping(*_range)])
    print(overlaps)
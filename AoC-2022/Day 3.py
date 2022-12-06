def priority(char: str) -> int:
    if char.isupper():
        return 26 + ord(char) - ord('A') + 1
    else:
        return ord(char) - ord('a') + 1

def chunks(_list: list, n: int):
    """Yield successive n-sized chunks from list.
    Ref: https://stackoverflow.com/a/312464
    """
    for i in range(0, len(_list), n):
        yield _list[i:i + n]

def part_1(input) -> int:
    rucksacks = [(set(rucksack[:len(rucksack) // 2]), set(rucksack[len(rucksack) // 2:])) for rucksack in input]
    priority_sum = sum([sum(map(priority, compartment_1.intersection(compartment_2))) for compartment_1, compartment_2 in rucksacks])
    return priority_sum

def part_2(input) -> int:
    groups = list(chunks(input, 3))
    rucksacks = [(set(r0), set(r1), set(r2)) for r0, r1, r2 in groups]
    priority_sum = sum([sum(map(priority, r0.intersection(r1).intersection(r2))) for r0, r1, r2 in rucksacks])
    return priority_sum


if __name__ == '__main__':
    INPUT_FILE = 'Day 3-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read().splitlines()
    print(part_1(input))
    print(part_2(input))
def chunks(_list: list, n: int, m: int):
    """Yield m-separated n-sized chunks from list.
    Ref: https://stackoverflow.com/a/312464
    """
    for i in range(0, len(_list), m):
        yield _list[i:i + n]

if __name__ == '__main__':
    INPUT_FILE = 'Day 6-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read()
    for idx, part in enumerate(chunks(input, 4, 1)):
        if len(set(part)) == 4:
            print(idx + 4)
            break
    for idx, part in enumerate(chunks(input, 14, 1)):
        if len(set(part)) == 14:
            print(idx + 14)
            break
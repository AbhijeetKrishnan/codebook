import re

from typing import List, Tuple

def chunks(_list: list, n: int):
    """Yield successive n-sized chunks from list.
    Ref: https://stackoverflow.com/a/312464
    """
    for i in range(0, len(_list), n):
        yield _list[i:i + n]

def process_stack_config(stack_config_strs: List[str]) -> List[List[str]]:
    stack_nums = list(map(int, filter(lambda ele: ele != '', stack_config_strs[-1].split(' '))))
    stack_config = [[] for _ in range(len(stack_nums))]
    stack_config_vals = stack_config_strs[:-1]
    stack_config_vals = [[line[i:i+3] for i in range(0, len(line), 4)] for line in stack_config_vals]
    # print(stack_config_vals)
    for row in stack_config_vals[::-1]:
        for idx, ele in enumerate(row):
            if ele != '   ':
                stack_config[idx].append(ele[1])
    return stack_config

def process_moves(moves_strs: List[str]) -> List[Tuple[int, int, int]]:
    PAT = r'move (\d+) from (\d+) to (\d+)'
    pat = re.compile(PAT)
    moves = [tuple(map(int, re.fullmatch(pat, line).groups())) for line in moves_strs]
    return moves

def simulate_move_part_1(stack_config, n, _from, to):
    for _ in range(n):
        ele = stack_config[_from - 1].pop()
        stack_config[to - 1].append(ele)

def simulate_move_part_2(stack_config, n, _from, to):
    part = stack_config[_from - 1][-n:]
    stack_config[_from - 1] = stack_config[_from - 1][:-n]
    stack_config[to - 1].extend(part)

if __name__ == '__main__':
    INPUT_FILE = 'Day 5-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read().splitlines()
        stack_config_strs = input[:input.index('')]
        moves_strs = input[input.index('') + 1:]

    stack_config = process_stack_config(stack_config_strs)
    moves = process_moves(moves_strs)
    for n, _from, to in moves:
        simulate_move_part_2(stack_config, n, _from, to)
    tops = ''.join([stack[-1] for stack in stack_config])
    print(tops)
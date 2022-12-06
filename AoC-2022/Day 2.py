from enum import IntEnum

class Action(IntEnum):
    ROCK = 0
    PAPER = 1
    SCISSORS = 2

    @staticmethod
    def from_char(char: str) -> 'Action':
        if char in ['A', 'X']:
            return Action.ROCK
        elif char in ['B', 'Y']:
            return Action.PAPER
        else:
            return Action.SCISSORS

    @staticmethod
    def outcome(action: 'Action', response: 'Action') -> int:
        if action == response:
            return 3
        elif action == (response + 1) % 3:
            return 0
        else:
            return 6
    
    @staticmethod
    def target(action: 'Action', outcome: 'Action') -> 'Action':
        if outcome == Action.ROCK:    # loss
            return Action((action - 1) % 3)
        elif outcome == Action.PAPER: # draw
            return action
        else:                         # win
            return Action((action + 1) % 3)


if __name__ == '__main__':
    INPUT_FILE = 'Day 2-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read()
    strategy = list(map(lambda s: tuple(Action.from_char(c) for c in s.split()), input.splitlines()))
    score = sum([Action.outcome(round[0], round[1]) + (round[1] + 1) for round in strategy])
    print(score) # Part 1
    score = sum([Action.outcome(round[0], Action.target(round[0], round[1])) + Action.target(round[0], round[1]) + 1 for round in strategy])
    print(score) # Part 2
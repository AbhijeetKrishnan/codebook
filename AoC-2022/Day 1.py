if __name__ == '__main__':
    INPUT_FILE = 'Day 1-input.txt'
    with open(INPUT_FILE) as inputfile:
        input = inputfile.read().splitlines()
    elf_calories = []
    curr_elf = 0
    for calorie in input:
        if calorie == '':
            elf_calories.append(curr_elf)
            curr_elf = 0
        else:
            curr_elf += int(calorie)
    elf_calories.append(curr_elf)
    elf_calories.sort(reverse=True)
    print('Part 1:', elf_calories[0])
    print('Part 2:', sum(elf_calories[:3]))
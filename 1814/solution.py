from collections import deque


def smallest_turns(snakes, ladders):
    transports = {**snakes, **ladders}

    queue = deque([(1, 0)])
    visited = {1}

    while queue:
        curr_square, turns = queue.popleft()

        if curr_square == 100:
            return turns

        for move in range(1, 7):
            next_square = curr_square + move

            if next_square <= 100:
                if next_square in transports:
                    next_square = transports[next_square]

                if next_square not in visited:
                    visited.add(next_square)
                    queue.append((next_square, turns + 1))

    return -1


# Dados do problema
snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}

print(f"O menor número de turnos é: {smallest_turns(snakes, ladders)}")

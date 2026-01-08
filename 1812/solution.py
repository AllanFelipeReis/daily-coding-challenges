from collections import deque


def solve_teams(students):
    teams = {}

    for student in students:
        if student in teams:
            continue

        queue = deque([(student, 0)])
        teams[student] = 0

        while queue:
            curr_student, curr_team = queue.popleft()

            for enemy in students[curr_student]:
                if enemy not in teams:
                    teams[enemy] = 1 - curr_team
                    queue.append((enemy, teams[enemy]))
                elif teams[enemy] == curr_team:
                    return False

    team_a = {s for s, t in teams.items() if t == 0}
    team_b = {s for s, t in teams.items() if t == 1}

    return team_a, team_b


# Teste 1 (Válido)
s1 = {0: [3], 1: [2], 2: [1, 4], 3: [0, 4, 5], 4: [2, 3], 5: [3]}
print(f"Resultado 1: {solve_teams(s1)}")

# Teste 2 (Inválido - Ciclo ímpar entre 2, 3 e 4)
s2 = {0: [3], 1: [2], 2: [1, 3, 4], 3: [0, 2, 4, 5], 4: [2, 3], 5: [3]}
print(f"Resultado 2: {solve_teams(s2)}")

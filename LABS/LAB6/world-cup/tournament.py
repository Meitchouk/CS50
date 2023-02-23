# Simulate a sports tournament

import csv
import sys
import random

# numero de simulaciones a realizar
N = 1000


def main():

    # revisa que se haya ingresado el nombre del archivo csv como argumento de la linea de comandos
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # lee los equipos del archivo csv y los guarda en una lista
    filename = sys.argv[1]
    with open(filename) as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            team = row
            team["rating"] = int(team["rating"])
            teams.append(team)

    counts = {}
    # simula n torneos y cuenta las victorias de cada equipo
    for simulation in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] = counts[winner] + 1
        else:
            counts[winner] = 1

    # imprime los resultados ordenados por porcentaje de victorias
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simula un partido por cada par de equipos
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    rounds = len(teams)
    if rounds >= 2:
        teams = simulate_round(teams)
        return simulate_tournament(teams)
    else:
        winner = teams[0]["team"]
        return winner


if __name__ == "__main__":
    main()

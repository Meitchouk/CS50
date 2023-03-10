#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (strcmp(name, candidates[candidate].name) == 0)
        {
            preferences[voter][rank] = candidate;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int voter = 0; voter < voter_count; voter++)
    {
        int rank = 0;
        while (true)
        {
            int candidate = preferences[voter][rank];
            if (candidates[candidate].eliminated)
            {
                rank ++;
            }
            else
            {
                candidates[candidate].votes++;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    int majority_votes = round(voter_count / 2);
    for (int candidate = 0; candidate < candidate_count; candidate ++)
    {
        if (candidates[candidate].votes > majority_votes)
        {
            printf("%s\n", candidates[candidate].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int minimum = candidates[0].votes;
    for (int candidate = 1; candidate < candidate_count; candidate++)
    {
        int candidate_votes = candidates[candidate].votes;
        if (candidate_votes < minimum && !candidates[candidate].eliminated)
        {
            minimum = candidate_votes;
        }
    }
    return minimum;
}

bool is_tie(int min)
{
    int remaining_candidates = candidate_count;
    int tie = 0;
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (candidates[candidate].eliminated)
        {
            remaining_candidates--;
        }
        else if (candidates[candidate].votes == min)
        {
            tie++;
        }
    }
    if (remaining_candidates == tie)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void eliminate(int min)
{
    for (int candidate = 0; candidate < candidate_count; candidate++)
    {
        if (candidates[candidate].votes == min)
        {
            candidates[candidate].eliminated = true;
        }
    }
    return;
}
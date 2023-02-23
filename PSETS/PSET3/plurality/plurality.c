#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
        // para cada candidato en la lista de candidatos
    {
        if (strcmp(name, candidates[i].name) == 0)
            // si el nombre del candidato es igual al nombre del voto
        {
            candidates[i].votes++;
            // entonces se le suma un voto al candidato
            return true;
            // y se retorna true
        }
    }
    return false;
    // si no se encuentra el candidato, se retorna false
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int maxvotes = 0;
    // se crea una variable para guardar el numero maximo de votos

    for (int i = 0; i < candidate_count; i++)
        // para cada candidato en la lista de candidatos
    {
        if (candidates[i].votes > maxvotes)
            // si el numero de votos del candidato es mayor al numero maximo de votos
        {
            maxvotes = candidates[i].votes;
            // entonces el numero maximo de votos es igual al numero de votos del candidato
        }
    }

    for (int i = 0; i < candidate_count; i++)
        // para cada candidato en la lista de candidatos
    {
        if (candidates[i].votes >= maxvotes)
            // si el numero de votos del candidato es mayor o igual al numero maximo de votos
        {
            //print_winner(candidates[i].name);
            printf("%s\n", candidates[i].name);
            // entonces se imprime el nombre del candi
        }
    }
    return;
}



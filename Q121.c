/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[100][50];
    for (int i = 0; i < n; i++)
        scanf("%s", names[i]);

    char unique[100][50];
    int count[100] = {0};
    int u = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < u; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique[u], names[i]);
            count[u++] = 1;
        }
    }

    int maxVotes = 0;
    char winner[50] = "";

    for (int i = 0; i < u; i++) {
        if (count[i] > maxVotes || (count[i] == maxVotes && strcmp(unique[i], winner) < 0)) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
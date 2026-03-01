#include <stdio.h>

char keys[10] = {'D','B','D','C','C','D','A','E','A','D'};

int checkscore(char std[]);
int statQ1(char ans[][10]);
int findHardest(char ans[][10]);

int main() {
    int i;
    char ans[8][10] = {
        {'A','B','A','C','C','D','E','E','A','D'}, 
        {'D','B','A','B','C','A','E','E','A','D'}, 
        {'E','D','D','A','C','B','E','E','A','D'}, 
        {'C','B','A','E','D','C','E','E','A','D'}, 
        {'A','B','D','C','C','D','E','E','A','D'}, 
        {'B','B','E','C','C','D','E','E','A','D'}, 
        {'B','B','A','C','C','D','E','E','A','D'}, 
        {'E','B','E','C','C','D','E','E','A','D'}  
    };

    for (i = 0; i < 8; i++) {
        printf("std %d => %d\n", (i+1), checkscore(ans[i]));
    }

    printf("Number of students who answered No.1 correctly: %d\n", statQ1(ans));

    printf("The hardest question is No. %d\n", findHardest(ans));

    return 0;
}

int checkscore(char std[]) {
    int score = 0;
    for (int j = 0; j < 10; j++) {
        if (std[j] == keys[j]) {
            score++;
        }
    }
    return score;
}

int statQ1(char ans[][10]) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (ans[i][0] == keys[0]) {
            count++;
        }
    }
    return count;
}

int findHardest(char ans[][10]) {
    int min_correct = 8; 
    int hardest_index = 0;

    for (int j = 0; j < 10; j++) { 
        int current_correct = 0; 
        for (int i = 0; i < 8; i++) { 
            if (ans[i][j] == keys[j]) {
                current_correct++;
            }
        }
        if (current_correct < min_correct) {
            min_correct = current_correct;
            hardest_index = j;
        }
    }
    
    return hardest_index + 1; 
}
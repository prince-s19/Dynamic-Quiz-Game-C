#include <stdio.h>
#include <stdlib.h>

struct Quiz
{
    char question[100];
    char options[4][50];
    int correctOption;
};

int main()
{
    int n, i, answer, score = 0;

    printf("Enter number of questions: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    struct Quiz *q = (struct Quiz *)malloc(n * sizeof(struct Quiz));

    // Input questions
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Question %d: ", i + 1);
        scanf(" %[^\n]", q[i].question);

        for (int j = 0; j < 4; j++)
        {
            printf("Option %d: ", j + 1);
            scanf(" %[^\n]", q[i].options[j]);
        }

        printf("Enter correct option (1-4): ");
        scanf("%d", &q[i].correctOption);
    }

    // Quiz start
    printf("\n--- QUIZ STARTED ---\n");

    for (i = 0; i < n; i++)
    {
        printf("\nQ%d: %s\n", i + 1, q[i].question);

        for (int j = 0; j < 4; j++)
        {
            printf("%d. %s\n", j + 1, q[i].options[j]);
        }

        printf("Your answer: ");
        scanf("%d", &answer);

        if (answer == q[i].correctOption)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong!\n");
        }
    }

    printf("\nFinal Score: %d / %d\n", score, n);

    free(q); // Free memory

    return 0;
}

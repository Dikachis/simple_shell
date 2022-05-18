#include <stdio.h>
#include <stdlib.h>

int main()

{

        size_t bytes_read;

        size_t size = 10;

        char *string;


        while(1)
        {
                printf ("$: ");

        /* These 2 lines are very important. */

        string = malloc(sizeof(char*)*size);

        bytes_read = getline (&string, &size, stdin);

                if (bytes_read == -1)

                {

                        printf("\n");
                        free(string);
                        exit(EXIT_SUCCESS);

                }

                        printf("%s", string);

                        printf ("%lu\n", bytes_read);
        }
        return 0;
}

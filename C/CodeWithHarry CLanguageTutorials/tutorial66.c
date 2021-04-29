//You have to fill in values to a template latter.txt
//
//Letter.txt looks something like this
//
//Thanks {{name}} for purchasing {{item}} from our outlet {{outlet}}.
//Please visit our outlet {{outlet}} for any kind of problems. We plan to serve you again.
//
//You have to read this file and replace these values:
//{{name}} - Harry
//{{item}} - Table Fan
//{{outlet}}   - Ram Laxmi fan outlet
//
//Use file functions in c to accomplish the same.
 
 
/* SOLUTION
To solve this problem. I have not edited the main file letter.txt,
but created a new file with replaced entries.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char name[20] = "Harry";
    char item[20] = "Table Fan";
    char outlet[30] = "Ram Laxmi fan outlet";

    FILE *read = NULL;
    read = fopen("letter.txt", "r");

    FILE *write = NULL;
    write = fopen("harry.txt", "w");

    char str[30];

    if (read == NULL)
    {
        printf("letter.txt failed to open\n");
        return 0;
    }
    else
    {
        fscanf(read, "%s", str);

        int count = 0;
        //str != "again."

        while (1)   // Its a code specific to the end point "again." of this file. Be careful.
        {
            //printf("%s kutta\n",str);
            if (!strcmp(str, "{{name}}"))
            {
                fprintf(write, "%s ", name);
            }
            else if (!strcmp(str, "{{item}}"))
            {
                //printf("Yes finally matched\n");
                fprintf(write, "%s ", item);
            }
            else if (!strcmp(str, "{{outlet}}"))
            {
                fprintf(write, "%s ", outlet);
            }
            else if (!strcmp(str, "{{outlet}}."))
            {
                fprintf(write, "%s. ", outlet);
            }
            else
            {
                fprintf(write, "%s ", str);
            }
            count++;
            if (!strcmp(str, "again."))
            {
                break;
            }

            fscanf(read, "%s", str);
        }
    }

    fclose(read);
    fclose(write);
    return 0;
}
//Name: Vijayagopal Krishnan (VJ)

#include <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>


int main()
{
    //creates the process id variable 
    pid_t PID; 
    // creates a file descriptor 
    FILE* fp;
    //integer variable to read value 
    int num = 0;
    //incrementor to do the sequence 100 times (50 for each process) 
    int incrementor = 1;
    do {
        //creates the process 
        PID = fork();
        //checks if there's no error 
        if (PID >= 0) {
            if (PID == 0)
            {
                //reads a file called F.txt or creates one if it doesn't exist 
                fp = fopen("F.txt", "w+");
                //checks if the file is not empty 
                if (ftell(fp)!= 0)
                {
                //reads the number in file and stores it to num 
                fscanf(fp, "%d", &num);
                }
                //closes the file 
                fclose(fp);
                //prints the number along with the process id 
                printf("%d %d", num, PID);
                //increments number 
                num++;
                //opens the file for writing 
                fp = fopen("F.txt", "w");
                //writes the number to the file 
                fputc(num, fp);
                //flushes the file descriptor 
                fflush(fp);
                //closes the file 
                fclose(fp);
            }
            else
            {
                fp = fopen("F.txt", "w+");
                if (ftell(fp)!= 0)
                {
                fscanf(fp, "%d", &num);
                }
                fclose(fp);
                printf("%d %d", num, PID);
                num++;
                fp = fopen("F.txt", "w");
                fputc(num, fp);
                fflush(fp);
                fclose(fp);
            }
         }
         //prints error
        else
        {
            printf("\n The fork process has failed \n");
            break;
        }
        incrementor++;
    } while (incrementor < 100);
    //tells the user the program has closed 
    printf ("\nThe program will now close! \n");
    fclose(fp);

}

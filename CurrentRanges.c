#include <stdio.h>      /* For printf() */
#include <assert.h>     /* For assert() */


int (*print)(const char *restrict , ...) = &printf;


/**
 * The below code has someother bugs, lol.
 */ 

void PrintContinousValuesInCurrentReadingSampleSet(int *CurrentReadingSampleSet)
{
    int index = 0; 
    int diff, count;
    int StartValue, EndValue;
    int Count = 1;
    int IsContinousValueDetectionStarted = 0;
    int IsPrintAllowed =0;
    const int SampleSetSize = 7;
    assert(CurrentReadingSampleSet != NULL);
    printf("Range    Readings\n");
    for(index =1; index < SampleSetSize; index++)
    {
        diff = CurrentReadingSampleSet[index] - CurrentReadingSampleSet[index-1];
        if((diff == 0) || (diff == 1))
        {
            if(IsContinousValueDetectionStarted == 0)
            {
                StartValue = CurrentReadingSampleSet[index-1];
                IsContinousValueDetectionStarted = 1;
            }            
            Count++;

            if(index == (SampleSetSize -1))
            {
                EndValue = CurrentReadingSampleSet[index];
                IsPrintAllowed = 1;
            }
        }
        else if(IsContinousValueDetectionStarted ==1)
        {
            EndValue = CurrentReadingSampleSet[index-1];
            IsPrintAllowed = 1;           
        }
        else{
            /* god knows what goes here */
        }
        if(IsPrintAllowed == 1)
        {
            print("%d - %d    %d\n",StartValue,EndValue,Count);
            IsContinousValueDetectionStarted = 0;
            IsPrintAllowed = 0;
            Count =1;
        }
    }
}


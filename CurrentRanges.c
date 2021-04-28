#include <stdio.h>      /* For printf() */
#include <assert.h>     /* For assert() */

/**
 * Design Decisions:
 * 1. The input is a pointer of type int.
 * 2. The pointer assumes that it is always pointed to an array.
 * 3. The array to which the input parameter is pointed to shall be of a fixed size 7. 
 * 4. This function shall print on console.
 * 5. If there is no continous values found then it shall print 
 *    "No Continous Values found".
 */ 

int (*print)(const char *restrict , ...) = &printf;

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
        if((diff > 1) && (IsContinousValueDetectionStarted ==1))
        {
            EndValue = CurrentReadingSampleSet[index-1];
            IsPrintAllowed = 1;           
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

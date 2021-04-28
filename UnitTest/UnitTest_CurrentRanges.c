#include "CurrentRanges.c"

static void TC_Testcase(void)
{
    /**
     * Few questions: 
     * Should the sample set be equal to fixed length ? 
     * or should we keep it constant length?
     * 
     * Answer : Dont want to do speculative coding
     * Hence fixing the sample set to a size say 7.
     */ 

    int CurrentReadingSampleSet[] = {3,3,4,7,7,7}
    PrintContinousValuesInCurrentReadingSampleSet(CurrentReadingSampleSet);
}



int main()
{
    return 0;
}
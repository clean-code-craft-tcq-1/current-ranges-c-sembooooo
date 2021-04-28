#include "../CurrentRanges.c"
#include "mocks.h"
#include <assert.h>

static void TC_Testcase_001(void)
{
    /**
     *  Decided not to put the size of the array fixed length.
     *  Hence fixing the sample set to a size say 7.
     */ 
    Reset_mocks();
    int CurrentReadingSampleSet[] = {3,3,4,7,11,13};
    print = &stub_printf;
    PrintContinousValuesInCurrentReadingSampleSet(CurrentReadingSampleSet);
    assert(call_printf == 1);
    assert(PrintfInputParam[0] == 3);
    assert(PrintfInputParam[1] == 4);
    assert(PrintfInputParam[2] == 3);
}



int main()
{
    TC_Testcase_001();
    return 0;
}
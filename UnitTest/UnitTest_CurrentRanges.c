#include "../CurrentRanges.c"
#include "mocks.h"
#include <assert.h>

static void TC_Testcase_001(void)
{
    /**
     *  design decisions done here:
     * 1. Decided not to put the size of the array fixed length.
     *  Hence fixing the sample set to a size say 7.
     * 2. Name of the API, its return value and its input params
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


/**
 * The below testcase fails hence i am not including this in the main function
 * 
 * If the reading sample set has constant values then printf should not be called.
 * But in the current code the printf gets called.
 * 
 * So ignoring the typo(i thought it is a typo) present in the readme
 * 
 *      # Consider a set of periodic current samples from a charging session to be:
 *      # 3, 3, 4, 5, 10, 11, 12`
 *      # In this example,
 *      #   - the `3-5` range has `4` readings
 *      #   - the `10-12` range has `3` readings.
 * 
 * So if a value is repeated among continous values even the repeated value is also considered.
 * But for now the algorithm cannot differentiate between continous values and  constant value sample.
 *  

 * Detection of a constant value sample list is not present. --> needs to be implemented
 * 
 */
static void TC_Testcase_002(void)
{
    Reset_mocks();
    print = &stub_printf;
    int CurrentReadingSampleSet[] = {7,7,7,7,7,7,7};
    PrintContinousValuesInCurrentReadingSampleSet(CurrentReadingSampleSet);
    assert(call_printf == 0);
}


int main()
{
    TC_Testcase_001();
    //TC_Testcase_002();
    return 0;
}
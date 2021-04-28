# Test Driven Ranges

This exercise extends the [Battery Monitoring] use-case.

The charging current varies during the process of charging.
We need to capture the range of current measurements -
what range of currents are most often encountered while charging.

> **DO NOT** jump into implementation! Read the example and the starting task below.

## Example

### Input

Consider a set of periodic current samples from a charging session to be:
`3, 3, 5, 4, 10, 11, 12`

### Functionality

The continuous ranges in there are: `3,4,5` and `10,11,12`.

The task is to detect the ranges and
output the number of readings in each range.

In this example,

- the `3-5` range has `4` readings
- the `10-12` range has `3` readings.

### Output

The expected output would be:

```
Range, Readings
3-5, 4
10-12, 3
```

## Tasks

Start test-driven development:

1. Establish quality parameters for your project: 
    1. What is the maximum complexity you would allow?  
       These questions are really interesting.  
       How can one even determine that without even knowing how to write the alogrithm ? Are there any metrics or is it just a guess ?  
       For now my guess would be 4.
    1. How much duplication would you consider unacceptable? What is the coverage you'll aim for?
       Same Questions as above  
    1. Adapt/adopt/extend the `yml` files from one of your workflow folders.

1. Write the smallest possible failing test.

1. Write the minimum amount of code that'll make it pass.

1. Write the next failing test.

Implement one failing test and at least one passing test:

- TC_Testcase_001 the name of a **passing** test
- TC_Testcase_002 the name of a **failing** test



To be honest, i am feeling this as a mind set development than a coding practice.
Hence felt a little different and tough when doing it. I am still little confused about this.
May be practising this a lot in real life may help me.
I am really not sure only if i am feeling like this.

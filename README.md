# smoothcpp
Easy to use first cross platform cpp library.

## goal
As a supplement to the c++ standard library.  
Has the following characteristics:  
* intuitive
* cross platform
* no other deps

## feature
* time
* string

## build
compiler need support c++ 17  
in source code dir, run `xmake`  

## feature details
the test dir is the best tutorial

### time lib funcs
* create Time object will record current time
* show method will print the time
* format method accept strftime format string to generate string
* static method sleep will sleep n milliseconds
* Time object can minus other one to get n milliseconds
* elapse method get n milliseconds from constructor or call reset
* reset the Time start time

### string lib funcs
* to_lower to_upper
* ltrim rtrim trim
* split_str split_chars
* join
* has_prefix has_suffix contains
* format, replcement of sprintf
* format, print vector and map values

## todo
* use test lib improve test process
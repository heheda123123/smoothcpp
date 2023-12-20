# smoothcpp
Easy to use first cross platform cpp library.

## goal
As a supplement to the c++ standard library.  
Has the following characteristics:  
* intuitive
* cross platform
* no other deps
* all funcs use doctest test

## feature
* time
* string
* any

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
* to_string, support print vector and map

### any lib funcs
* Any class construct with bool/short/int/double/string(const char*)
* Any object can cast to above type
* Different types of conversions should be as intuitive as possible

## todo
* add log lib
* add argparse lib

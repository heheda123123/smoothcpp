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
* Time class
* string funcs
* Any class
* Option class

## build
compiler need support c++ 17  
in source code dir, run `xmake`  

## feature details
the test dir is the best tutorial

### Time class
* create Time object will record current time
* show method will print the time
* format method accept strftime format string to generate string
* static method sleep will sleep n milliseconds
* Time object can minus other one to get n milliseconds
* elapse method get n milliseconds from constructor or call reset
* reset the Time start time

### string funcs
* to_lower to_upper
* ltrim rtrim trim
* split_str split_chars
* join
* has_prefix has_suffix contains
* format, replcement of sprintf
* to_string, support print vector and map

### Any class
* Any class construct with bool/short/int/long/float/double/string/const char*/unsigned ...
* Any object can cast to above type
* Different types of conversions should be as intuitive as possible

### Option class
* Create Option object with program intro
* add method set must arguments, need indicate arg_name arg_type arg_desc, optional default_value in the end
* add_opt method set optional arguments
* parse method parse argc and argv
* get method return Any object
* has method judge if arg exists

## todo
* add log lib

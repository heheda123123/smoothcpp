# smoothcpp
Easy to use first cross platform CPP library.

## feature
* time
* string

## build
need support c++ 17  
test in windows and linux  
in source code dir, run `xmake`  

## feature details
the test/ dir is the best tutorial

### time lib funcs
* create Time object will record current time
* show method will print the time
* format method accept strftime format string to generate string
* static method sleep will sleep n milliseconds
* Time object can minus other one to get n milliseconds

### string lib funcs
* to_lower to_upper
* ltrim rtrim trim
* split_str split_chars
* join
* has_prefix has_suffix contains
* format, replcement of sprintf
* format, print vector values
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
### build test
```
xmake f --test=y
xmake test
```

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
* format, replcement of ssprintf
* to_string, support commong container
* hexdump, print string with readable format 
* gbk2utf8, utf82gbk (only in windows)

### Any class
* Any class construct with bool/int/double/string/const char*/vector/map
* Strings and numbers can be converted to each other

### Option class
* useful argument parse tools
* Create Option object with program intro
* add method set must arguments, need indicate arg_name arg_type arg_desc [default_value]
* add_opt method set optional arguments
* parse method parse argc and argv
* get method return Any object
* has method judge if arg exists in parse results

## todo
* log
* thread pool
* json
* xml
* reactor
* http
* base64/md5/sha256/aes
* compress

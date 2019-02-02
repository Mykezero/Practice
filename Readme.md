# Readme
Installation Notes

#### Packages
* sudo apt-get install build-essential
* sudo apt-get install git

#### Libraries
* cpputest    - https://github.com/cpputest/cpputest
* termbox     - https://github.com/nsf/termbox

##### Compiling CppUTest
* sudo apt-get install autotools
* sudo apt-get install autoconf
* sudo apt-get install automake
* sudo apt-get install libtool
* ./autogen.sh 
* ./install-sh 
* ./configure

#### Running Tests
make tests && make cover && make report

#### Running Main
make main

#### Auto-Run Tests
watch -n .5 -x make

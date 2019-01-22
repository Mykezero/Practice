# Readme
Installation Notes

#### Packages
sudo apt-get install build-essential
sudo apt-get install git

#### Libraries
cpputest    - https://github.com/cpputest/cpputest
termbox     - https://github.com/nsf/termbox

#### Extensions
Install VSCode LCov 1.10 since 2.0 does not work with  Linux Mint 19.1 Tessa. 

#### VSCode LCov Commands
CTRL-T - Show Coverage Report
CTRL-T - Enable Watchers

#### Running tests
make tests && make cover && make report

#### Running main
make main
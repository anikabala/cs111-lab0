# A Kernel Seedling
This lab was an introduction to creating kernel modules, particularly, we were interested in locating and counting processes running on our computers. 

## Building
All kernel modules need an initialization (init) and an exit function that were provided in this case. These functions ensure smooth loading/unloading of our kernel module. To compile, I used the make function. 

## Running
To run, I used insmod to properly insert the module. Specifically, the command was:

sudo insmod proc_count.ko

To print out the contents of the /proc/count file, I used the cat command:

cat /proc/count

The results I got from my machine varied between 141-142, meaning that many running processes. 


## Cleaning Up
To clean what was built, I used the rmmod function, which just removes it from where it was previously inserted, allowing further testing and use: 

sudo rmmod proc_count.ko

Another cleanup mechanism that overall allows to continually compile, change, and test was simply the make clean function. This allows for recompilation and removes the libraries and functions Linux auto-adds during compilation.

make clean

## Testing
For testing, we used the given test script. 

python -m unittest

The results were that the function passed the three test cases with output 'OK'

Running uname -r -s -v outputted Linux 5.14.8-arch1-1, meaning the kernel version is 5.14.8

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

# Tests

Tests use [Catch2](https://github.com/catchorg/Catch2). Install Catch2 with your distro's package manager or 
install them from source by.  

To install Catch2 from source
```bash
$ git clone https://github.com/catchorg/Catch2.git
$ cd Catch2
$ cmake -Bbuild -H. -DBUILD_TESTING=OFF
$ sudo cmake --build build/ --target install
```
*Taken straight from their github documentation. Don't forget to give them a star ;)*

# Running Tests

Should be straight forward. Once in the project source directory...
```bash
$ cd Tests
$ mkdir Build
$ cd Build
$ cmake ..
$ make
$ ./DTSTests
```

Tests should then run.
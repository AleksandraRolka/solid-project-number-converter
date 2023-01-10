### _SOLID programming basics university course project_

---

# Number converter

A simple number converter allowing conversion from decimal number to binary or a binary number to its decimal equivalent.

- program is a single threaded standalone command line C++ application
- uses Boost, installed library is required to run the program
- parameters are passed through command line
- proper makefile is prepared

  - to compile run:
    ```
    make
    ```
  - to clean from \*.o files, _main_ and _tests_ executive files:
    ```
    make clean
    ```
  - to run clean and also compile main program and unit tests:
    ```
    make all
    ```
  - to execute main:
    ```
    make run <value> <source_conversion_type> <*target_conviersion_type*>
    ```
    or :
    ```
    ./main <value> <source_conversion_type> <target_conversion_type>
    ```
    For example:
    ```
    make run 1500100900 decimal binary
    ```
  - to run unit tests:
    ```
    make ut
    ```
    or :
    ```
    ./ut/tests
    ```

- conversion result is displayed on the screen
- currently supported conversions:
  - decimal <--\> binary
- it can be easily extended for new conversions (i.e. to/from hexadecimal, octal)

<br />

---

<br />

> #### Instruction used for installing **boost** and **gtest** libraries on Ubuntu:
>
> - https://www.how2shout.com/linux/how-to-install-boost-c-on-ubuntu-20-04-or-22-04/
> - https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

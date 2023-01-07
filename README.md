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
  - to clean from \*.o files _main_ executive file:
    ```
    make clean
    ```
  - to clean and compile:
    ```
    make all
    ```
  - to execute:
    ```
    make run <value> <source_conversion_type> <target_conversion_type>
    ```
    For example:
    ```
    make run 1500100900 decimal binary
    ```

- conversion result is displayed on the screen
- currently supported conversions:
  - decimal <--\> binary
- it can be easily extended for new conversions (i.e. to/from hexadecimal, octal)

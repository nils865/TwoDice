# TwoDice

A programm that rolls two random dice and calculates the chance of each output occurring

⚠ **WARNING** using ~10.000.000 Threads is not recommended and might break your Computer

## Benchmarks

Benchmarks don't give out the ratio of each number occurring. They calculate a score `sample_size / time_in_ms` which you can use to determine the Single Threaded and Multithreaded speed of a computer. The programm will ask you to specify a Thread count. Set it to 1 for Single Threaded testing or use any number for Multithreaded testing. It is recommended to use the number of threads that your CPU actually has and not more.

Arguments:

- `-b` for sample size 10.000.000
- `-bc` for custom benchmarks:
  - `-bc 0` choose the sample size
  - `-bc 1` for sample size 10.000.000
  - `-bc 2` for sample size 1.000.000.000
  - `-bc 3` for sample size 10.000.000.000

Example scores for Test 1:

- Core i5-12600k with 16 Threads: 500.000
- Ryzen 5 5600X with 12 Threads 357.142
- Core i7-4770k with 8 Threads: 156.250
- Core i7-3770 with 8 Threads: 156.250
- Ryzen 5 4500U with 6 Threads: 136.986

## TODO

- [X] Implementing Multithreading
- [X] Trying to make Multithreading not slower than singlethreading
- [X] Add true randomness
- [X] Add a console based ui
- [X] Add a benchmark option

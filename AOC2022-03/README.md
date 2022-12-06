# [Day 3](https://adventofcode.com/2022/day/3)

## Part 1
This segment, as has been the case with first parts so far, was quite simple. As I am trying to get into the habit of avoiding "magic numbers" and writing code that can be run on varied inputs, I considered allowing a given rucksack of size `N` to be split into `i` compartments, where `i` divides `N` without a remainder. However, I decided to save myself the headache that such an implementation would cause if `i` did *not* divide `N` evenly and instead hard-coded the halfway pivot.

## Part 2
As I mentioned in part 1, I try to write code that is valid for a variety of input parameters so as to improve its scope and usefulness. I anticipate that this will be useful to me in the future, both within the Advent of Code and my career as a software engineer. In any case, this script can consider any `GROUP_SIZE`, which wasn't strictly necessary to add but was easy enough to implement.
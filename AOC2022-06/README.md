# [Day 6](https://adventofcode.com/2022/day/6)

## Part 1
I agonized over which language to use for the day 6 challenge. Whenever I see problems involving a moving window, my first instinct is to jump to C or Java; I want something that will allow direct pointer manipulation with minimal overhead. However, as I got started writing my solution in C, I found myself against a bit of a wall. With memory allocation, deallocation, and pointer arithmetic starting to pile up, I made the executive decision to switch back to my tried and true Python scripting.

Although my final Python script is nowhere near as efficient as an O(n) C or Java solution might have been, it *was* significantly less painful to write than the alternatives. And I got the feeling that the window size might change at some point, so I wrote a more generic solution that varies with a parameter I called `WINDOW_SIZE`. My software dev Spider-Sense told me that this was a) Better code, as it was reusable for any window size and b) Something that was likely to come up in part 2.

## Part 2
Man, I am *good*. I just had to change my `WINDOW_SIZE` from part 1 and I had my part 2 solution all ready to go!

# [Day 5](https://adventofcode.com/2022/day/5)

## Part 1
Sometimes, the most efficient way to code is to be a little bit lazy. As I began the challenge for day 5, I noticed two things about the "drawing" of the starting stacks of crates (pictured below).
```
    [M]             [Z]     [V]    
    [Z]     [P]     [L]     [Z] [J]
[S] [D]     [W]     [W]     [H] [Q]
[P] [V] [N] [D]     [P]     [C] [V]
[H] [B] [J] [V] [B] [M]     [N] [P]
[V] [F] [L] [Z] [C] [S] [P] [S] [G]
[F] [J] [M] [G] [R] [R] [H] [R] [L]
[G] [G] [G] [N] [V] [V] [T] [Q] [F]
 1   2   3   4   5   6   7   8   9 
```
First, it's only given once. This means, right out of the gate, that writing a general function to read these drawings is not necessarily worth it since said function would need to handle exactly one case. Second, this drawing just looks *hard* to parse via code. Sure, I could index by spaces and use the brackets as delimiters and dynamically create a jagged array of stacks... Or I could just hard-code the stacks into my program.

And so I did exactly that (and, to be honest, I think I spent less time hard-coding this input than I would have spent coding, debugging, and testing a parser). The directions themselves were my only program inputs; I just cut the drawing out of `input.txt`. Thankfully, the directions followed a consistent, string-delineated format that I could easily split into the correct array operations. I did make a mistake at first in not realizing that, for this part of the challenge, the crates should be moved one by one. Instead, my script first used Python array slices to move groups of crates all at once. After realizing my mistake, I went over to good old `.pop()` calls.

## Part 2
Good news! That piece of code that I mentioned in part 1 that uses Python array slices to move crates around didn't go to waste. With minimal changes to my code from part 1 (yay for reusability!), I had my part 2 solution.
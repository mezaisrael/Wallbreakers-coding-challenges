At first I just simply looped through the matrix and swaped them, then I could invert the numbers on a second pass. I then realized that it was redundant to go through this process if the numbers were no equal. I also realized that if the front and the back of my comparison were equal I did not really have to swap, just invert each of them. I also opted to iterate with the loop with iteratos. It looks shorter this way. This soulution runs in O(n) where n is the number of elements in the matrix

some stats
Runtime: 12 ms, 100% faster than other c++ leetcode submissions
Memory Usage: 9.4 MB, 99.22% more memory efficient. 
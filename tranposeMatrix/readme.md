If your look at the input you can see that  each first element of each array is in the first element ouf the output. The secon element of each array is in the second array of the output and so on. So it is easy to visualize that the number in input[i][j] will be in the  output[j][i]. All we have to is make a second matrix that we can fill in this manner when we iterate throught he original array. The tricky part is implementing it since it can be tricky. This soultion runs in O(n) where n is the elements in the matrix.


I have to share this stats. 
Runtime: 28 ms, faster than 97.37% of C++ online submissions for Transpose Matrix.
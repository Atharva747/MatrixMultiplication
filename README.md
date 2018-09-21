# Neo
## Parallelized matrix operations library
- Utilizes multiple cores in the cpu using threads in C and assigns each core a particular (row, column) pair.
- Uses Strassen's algorithm to bring runtime for matrix multiplication down from O(n^3) to O(n^log(7))
- Parallizes determinant operation modulo 1000000007.

## Performance improvements
(For two 1000 x 1000 matrices)
- 9.5x performance boost for finding the matrix product

(For one 1000 x 1000 matrix)
- 8x performance boost for finding the determinant modulo 1000000007

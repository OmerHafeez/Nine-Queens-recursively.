# Nine-Queens-recursively
Solve the Nine Queens problem recursively. The objective is to place nine queens on an empty
chessboard (9x9 matrix) so that no queen is “attacking” any other, i.e., no two queens are in the
same row, the same column, or along the same diagonal?
Show a solution on the screen and wait for the user to press a key before displaying the next
solution. 
Your function prototype must be as follows:
bool nQueens(char **b /*board*/, int n=9/*size of board*/,
int r=0/*current row number*/, int col=1/*current column number*/);

void print_spiral(int mat[][N_MAX], int m, int n, int k) {
  if (m <= 0 || n <= 0)
    return;
  if (m == 1) {
    for (int j = 0; j < n; j++)
      cout << mat[k][k+j] << " ";
    return;
  }
  if (n == 1) {
    for (int i = 0; i < m; i++)
      cout << mat[k+i][k] << " ";
    return;
  }
  // print from top left
  for (int j = 0; j < n - 1; j++)
  {
    cout << "TLmat[" << k << "][" << k+j <<"]" << endl;
    cout << mat[k][k+j] << " " << endl;
  }
  // print from top right
  for (int i = 0; i < m - 1; i++)
  {
    cout << "TRmat[" << k + i << "][" << k+n-1 <<"]" << endl;
    cout << mat[k+i][k+n-1] << " " << endl;
  }
  // print from bottom right
  for (int j = 0; j < n - 1; j++)
  {
    cout << "BRmat[" << k + m -1 << "][" << k+n - 1 - j <<"]" << endl;
    cout << mat[k+m-1][k+n-1-j] << " " << endl;
  }
  // print from bottom left
  for (int i = 0; i < m - 1; i++)
  {
    cout << "BLmat[" << k + m -1 -i << "][" << k <<"]" << endl;
    cout << mat[k+m-1-i][k] << " " << endl;
  }
  print_spiral(mat, m-2, n-2, k+1);
}
 
void print_spiral_helper(int mat[][N_MAX], int m, int n) {
  print_spiral(mat, m, n, 0);
}

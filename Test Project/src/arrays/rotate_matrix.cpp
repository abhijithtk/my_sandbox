void rotate_matrix_cw_90(int **m, int n)
{
    int i, j;

    // first mirror the matrix along the diagnal line.
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }

    // mirror the matrix horizontally.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n/2; j++)
        {
            int tmp = m[i][j];
            m[i][j] = m[i][n - j - 1];
            m[i][n - j - 1] = tmp;
        }
    }
}

using System;

public class MyProgram
{
    static bool csakotos(int sor, int m, int[,] jegyek)
    {
        int i = 0;
        while ((i<m) && (jegyek[sor, i] == 5))
        {
            i++;
        }
        return (i >= m);
    }

    public static void Main(string[] args)
    {
        int n = 5;
        int m = 4;

        int db = 0;
        int[,] jegyek = { { 5, 5, 4, 3 }, { 5, 5, 5, 5 }, { 5, 3, 2, 4 }, { 5, 5, 5, 5 }, { 5, 3, 4, 5 } };

        for (int i = 0; i < n; i++)
        {
            if(csakotos(i,m, jegyek))
            {
                db++;
            }
        }

        Console.WriteLine($"db: {db}");
    }
}

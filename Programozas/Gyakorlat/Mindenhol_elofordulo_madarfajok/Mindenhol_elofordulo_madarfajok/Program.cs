using System;
using System.Collections;
using System.Collections.Generic;

public class MyProgram
{
    static bool nincs0(int sor, int m, int[,] madarak)
    {
        int i = 0;
        while ((i < m) && (madarak[sor, i] > 0))
        {
            i++;
        }
        return (i >= m);
    }

    public static void Main(string[] args)
    {
        int n = 4;
        int m = 5;

        int db = 0;
        int[,] madarak = new int[n, m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                madarak[i, j]= int.Parse(Console.ReadLine());
            }
        }
        //int[,] madarak = { { 1, 1, 2, 1, 0 }, { 2, 3, 1, 3, 1 }, { 4, 1, 0, 2, 3 }, { 3, 3, 1, 1, 2 }};
        List<int> sorszamok = new List<int>();

        for (int i = 0; i < n; i++)
        {
            if (nincs0(i, m, madarak))
            {
                db++;
                sorszamok.Add(i+1);
            }
        }

        Console.WriteLine(db);
        sorszamok.ForEach(i => Console.Write("{0} ", i));
    }
}

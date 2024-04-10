using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int N; // Number of locations
        int M; // Number of days

        // Input
        string str = Console.ReadLine();
        N = Convert.ToInt32(str.Split(' ')[0]);
        M = Convert.ToInt32(str.Split(' ')[1]);

        int[,] Hi = new int[N, M];

        // Filling the temperature data
        for (int i = 0; i < N; i++)
        {
            string[] rowValues = Console.ReadLine().Split(' ');
            for (int j = 0; j < M; j++)
            {
                 Hi[i, j] = int.Parse(s: rowValues[j]);
            }
        }

        float threshold = (float)N/2;

        // Find days with at least half of the locations showing an increase
        List<int> napok = new List<int>();
        for (int j = 0; j < M - 1; j++)
        {
            int count = 0;
            for (int i = 0; i < N; i++)
            {
                if (Hi[i, j] < Hi[i, j + 1])
                {
                    count++;
                }
            }

            int e = 0;
            while (e<=N && !(count < threshold))
            {
                e++;
            }
            bool van = (e <= N);

            if (!van)
            {
                napok.Add(j+2);
            }
        }
        int K = napok.Count;

        // Output
        Console.Write(K);

        // Output the days with temperature increase
        for (int i = 0; i < napok.Count; i++)
        {
            Console.Write($" {napok[i]}");
        }
    }
}

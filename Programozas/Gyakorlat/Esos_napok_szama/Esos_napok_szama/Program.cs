using System;

public class MyProgram
{ 

    public static void Main(string[] args)
    {
        int N; // 0 <= N <= 100
        int[] Mi; // 0 <= Mi <= 1000
        int db = 0;

        N = int.Parse(Console.ReadLine());
        Mi = new int[N + 1];

        for (int i = 0; i < N; i++)
        {
            Mi[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < N; i++)
        {
            if (Mi[i] > 0)
            {
                db++;
            }
        }

        Console.WriteLine(db);

    }
}
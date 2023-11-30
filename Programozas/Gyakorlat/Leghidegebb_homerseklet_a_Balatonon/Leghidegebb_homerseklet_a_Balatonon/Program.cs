using System;

public class MyProgram
{

    public static void Main(string[] args)
    {
        int N; // 0 <= N <= 100
        int[] H; // 0 <= H <= 50
        int minert = 1000;

        N = int.Parse(Console.ReadLine());
        H = new int[N + 1];

        for (int i = 0; i < N; i++)
        {
            H[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < N; i++)
        {
            if (H[i] < minert)
            {
                minert = H[i];
            }
        }

        Console.WriteLine(minert);

    }
}
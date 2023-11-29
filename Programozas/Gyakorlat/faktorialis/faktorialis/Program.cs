using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n, fakt=1;

        do
        {
            Console.WriteLine("Adja meg az n-1: ");
            n = int.Parse(Console.ReadLine());
        } while (n<0);

        for(int i = 1; i <=n; i++)
        {
            fakt *= i;
        }

        Console.WriteLine($"Az {n} faktorialisa: {fakt}");
    }
}

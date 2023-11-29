using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n;
        
        do
        {
            Console.WriteLine("Adjon meg egy szamot: ");
            n = int.Parse(Console.ReadLine());
            Console.WriteLine("-------------------------------");
        } while (n < 0);

        int[] negyzetszam = new int[n+1];

        for (int i = 1; i <= n; i++)
        {
            negyzetszam[i] = i * i;
            Console.Write($"{negyzetszam[i]} ");
        }

    }

}

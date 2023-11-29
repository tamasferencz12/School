using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int x = 0, y = 1, fib = 0, n;

        Console.WriteLine("Adja meg egy szamot: ");
        n = int.Parse(Console.ReadLine());

        while (fib < n)
        {
            Console.WriteLine(fib);
            fib = x + y;
            x = y;
            y = fib;
        }
        
    }
       
}

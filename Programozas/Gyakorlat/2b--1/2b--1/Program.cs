using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n = 0;
        int x = 1;

        Console.WriteLine("Select your number: ");
        n = Convert.ToInt32(Console.ReadLine());

        for(int i = 1; i <= n; i++)
        {
            x *= i;
        }

        Console.WriteLine($"N! = {x}");
    }
}

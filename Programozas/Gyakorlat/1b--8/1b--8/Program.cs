using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int age, inYears;
        string name = "Tamas";

        age = int.Parse(Console.ReadLine());

        inYears = age + 2050 - 2023;

        Console.WriteLine(inYears , name);
    }
}

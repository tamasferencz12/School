using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        char j1, j2;

        Console.WriteLine("person 1's choice: ");
        j1 = Convert.ToChar(Console.ReadLine());
        Console.WriteLine("person 2's choice: ");
        j2 = Convert.ToChar(Console.ReadLine());

        if(j1 == j2)
        {
            Console.WriteLine("Equal!");
        }
        else if ((j1 == 'k' && j2 == 'o') || (j1 == 'o' && j2 == 'p') || (j1 == 'p' && j2 == 'k' ))
        {
            Console.WriteLine("Person 1 won!!!");
        }
        else
        {
            Console.WriteLine("Person 2 won!!!");
        }
    }
}

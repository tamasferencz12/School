using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n;
        int paros = 0, paratlan = 0;

        Console.WriteLine("Adja meg az n-t: ");
        n = int.Parse(Console.ReadLine());

        int[] szamok = new int[n + 1];

        for (int i = 1; i <= n; i++)
        {
            Console.WriteLine("Adja meg a szamokat: ");
            szamok[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 1; i <= n; i++)
        {
            if (szamok[i] % 2 == 0)
            {
                paros++;
            }
            else
            {
                paratlan++;
            }
        }

        if (paros > paratlan)
        {
            Console.WriteLine("Tobb a paros!");
        }
        else
        {
            Console.WriteLine("Tobb a paratlan!");
        }
    }

}

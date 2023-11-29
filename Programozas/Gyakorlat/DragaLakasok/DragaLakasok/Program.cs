using System;

public class MyProgram
{
     struct Lakas
    {
        public int ter;
        public int ar;
    }
    public static void Main(string[] args)
    {
        int k,n;
        int db = 0;
        int[] dragak = new int[100];
        //Console.Error.Write("Adja meg a lakasok szamat es arat: ");
        string[] str = Console.ReadLine().Split(' ');
        n = Convert.ToInt32(str[0]);
        k = Convert.ToInt32(str[1]);

        Lakas[] lakasok = new Lakas[n];

        for (int i = 0; i < n; i++)
        {
            //Console.Error.Write($"{i + 1} .lakas ara es alapterulete: ");
            string[] str2 = Console.ReadLine().Split(' ');
            lakasok[i].ter = Convert.ToInt32(str2[0]);
            lakasok[i].ar = Convert.ToInt32(str2[1]);
        }

        for (int i = 0; i < n; i++)
        {
            if (lakasok[i].ar > k)
            {
                dragak[db] = i+1;
                db++;
            }
        }
        Console.Error.Write($"{db} ");
        for (int i = 0; i < db; i++)
        {
            Console.Error.Write($"{dragak[i]} ");
        }
    }
}
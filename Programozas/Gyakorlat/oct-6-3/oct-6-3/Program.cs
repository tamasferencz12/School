using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n;
        int[] m;
        int db;
        bool jo;
        Console.Error.Write("Hany nap: ");
        n = int.Parse(Console.ReadLine());
        m = new int[n];
        for(int i = 1; i <= n; i++)
        {
            do
            {
                Console.Error.Write("{0}. menny: ", i);
                m[i - 1] = Convert.ToInt32(Console.ReadLine());
            } while (!(m[i - 1] >= 0 && m[i - 1] <= 1000));
        }
        db = 0;
        for(int i = 1; i <= n; i++)
        {
            if (m[i - 1] > 0)
            {
                db = db + 1;
            }
        }

        Console.Error.Write("Esos napok szama: ");
        Console.WriteLine(db);
    }
}

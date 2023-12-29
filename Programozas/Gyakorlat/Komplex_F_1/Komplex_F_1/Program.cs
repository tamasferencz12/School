using System;

public class MyProgram
{
    struct Tf
    {
        public int Ke;
        public int Ve;
    }

    public static void Main(string[] args)
    {
        int n, m, hossz;
        Tf[] feluj = new Tf[200];

        string str = Console.ReadLine();
        n = Convert.ToInt32(str.Split(' ')[0]);
        m = Convert.ToInt32(str.Split(' ')[1]);

        for (int i = 0; i < m; i++)
        {
            str = Console.ReadLine();
            feluj[i].Ke = Convert.ToInt32(str.Split(' ')[0]);
            feluj[i].Ve = Convert.ToInt32(str.Split(' ')[1]);
        }

        //a)
        hossz = feluj[0].Ve - feluj[0].Ke;

        for (int i = 0; i < m; i++)
        {
            if (feluj[i].Ve - feluj[i].Ke < hossz)
            {
                hossz = feluj[i].Ve - feluj[i].Ke;
            }
        }
        //b)
        int kiszamol(int i)
        {
            int db = 0;

            for (int j = 0; j < m; j++)
            {
                if (feluj[j].Ke <= i && i <= feluj[j].Ve)
                {
                    db++;
                }
            }

            return db;
        }

        int[] ut = new int[n];
        for (int i = 0; i < n; i++)
        {
            ut[i] = kiszamol(i);
        }

        bool van;
        int index = 0;
        while (index < n && ut[index] < 3)
        {
            index++;
        }
        van = index < n;

        //Kiiras
        //a)
        Console.WriteLine(hossz);
        //b)
        Console.WriteLine(van ? index : -1);
        //c)
        Console.WriteLine();
        //d)
        Console.WriteLine();
    }
}
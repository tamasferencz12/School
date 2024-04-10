using System;

public class MyProgram
{

    public static void Main(string[] args)
    {
        //jatekos szamai
        string beolvas = Console.ReadLine();
        string[] str1 = beolvas.Split(' ');
        int[] Sz = new int[6];
        for (int i = 0; i < 5; i++)
        {
            Sz[i] = Convert.ToInt32(str1[i]);
        }

        //szelveny ara
        int Ar;
        Ar = Convert.ToInt32(Console.ReadLine());

        //nyeremeny
        string[] str3 = Console.ReadLine().Split(' ');
        int[] Nyer = new int[6];
        for (int i = 0; i < str3.Length; i++)
        {
            Nyer[i] = Convert.ToInt32(str3[i]);
        }

        //kihuzott szamok
        int[,] L = new int[52, 5];

        for (int i = 0; i < 52; i++)
        {
            string[] rowValues = Console.ReadLine().Split(' ');
            for (int j = 0; j < 5; j++)
            {
                L[i, j] = int.Parse(rowValues[j]);
            }
        }

        //a)
        int[] kihuzott = new int[53];

        int dbKihuzott = 0;
        for (int i = 0; i < 52; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                bool van = false; int k = 0;
                while (!van && k < 5)
                {
                    if (Sz[k] == L[i, j])
                    {
                        van = true;
                        dbKihuzott++;
                    }
                    else
                    {
                        k++;
                    }
                }
                kihuzott[i] = dbKihuzott;
            }
        }

        int maxert = kihuzott[0];
        int maxind = 0;

        for (int i = 0; i < 52; i++)
        {
            if (kihuzott[i] > maxert)
            {
                maxert = kihuzott[i];
                maxind = i;
            }
        }

        //b)

        int[] nyeremeny = new int[53];

        for (int i = 0; i < 52; i++)
        {
            switch (kihuzott[i])
            {
                case 2:
                    nyeremeny[i] = 40000;
                    break;
                case 3:
                    nyeremeny[i] = 100000;
                    break;
                case 4:
                    nyeremeny[i] = 600000;
                    break;
                case 5:
                    nyeremeny[i] = 1200000;
                    break;

                default:
                    nyeremeny[i] = 0;
                    break;
            }
        }

        int sum = 0;
        for (int i = 0; i < 52; i++)
        {
            sum += nyeremeny[i];
        }


        //Kiiras
        //a)
        Console.WriteLine("#");
        Console.WriteLine(maxind+1);
        //b)
        Console.WriteLine("#");
        Console.WriteLine(sum);
        //c)
        Console.WriteLine("#");
        Console.WriteLine();
        //d)
        Console.WriteLine("#");
        Console.WriteLine();
        //e)
        Console.WriteLine();
    }
}
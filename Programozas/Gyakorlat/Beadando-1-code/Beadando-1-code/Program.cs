using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        // Ferencz Tamás, G0820E, tamasferencz25@gmail.com

        /*
            Ismerjük Magyarország összes településének távolságát Kukutyintól és Piripócstól.
                Készíts programot, amely megadja azon települések számát, amelyek közelebb vannak Kukutyin-
            hoz, mint Piripócshoz!
                Bemenet
            A standard bemenet első sorában a települések száma van (1≤N≤100), alatta soronként
            egy-egy település távolsága Kukutyintól (1≤K≤300), illetve Piripócstól (1≤P≤300), egy szóköz-
            zel elválasztva.
                Kimenet
            A standard kimenet egyetlen sorába a Kukutyinhoz közelebb lévő települések számát kell
            kiíratni! 
        */

        // DEKLARACIO
        int N; // 1 <= N <= 100
        int db = 0; // darabszam
        int[] K;// 1 <= K <= 300
        int[] P; // 1 <= P <= 300

        // BEOLVASAS
        N = int.Parse(Console.ReadLine());

        K = new int[N];
        P = new int[N];

        for (int i = 0; i < N; i++)
        {
            string[] str = Console.ReadLine().Split(' ');
            K[i] = Convert.ToInt32(str[0]);
            P[i] = Convert.ToInt32(str[1]);
        }

        // FELDOLGOZAS
        for (int i = 0; i < N; i++)
        {
            if (K[i] < P[i])
            {
                db++;
            }
        }

        // KIIRATAS
        Console.WriteLine(db);
    }
}
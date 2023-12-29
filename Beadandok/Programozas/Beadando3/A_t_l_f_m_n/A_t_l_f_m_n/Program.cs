using System;
using System.Collections;
using System.Collections.Generic;

public class MyProgram
{

    public static void Main(string[] args)
    {
        // Ferencz Tamás, G0820E, tamasferencz25@gmail.com

        /*
                A meteorológiai intézet az ország N településére adott M napos időjárás előrejelzést, az adott te-
            lepülésen az adott napra várt legmagasabb hőmérsékletet.
            Készíts programot, amely megadja azokat a napokat, amikor legalább a települések felében mele-
            gedés várható az előző naphoz képest!
                Bemenet
            A standard bemenet első sorában a települések száma (1≤N≤1000) és a napok száma
            (1≤M≤1000) van. Az ezt követő N sorban az egyes napokra jósolt M hőmérséklet értéke találha-
            tó (-50≤Hi,j≤50).
                Kimenet
            A standard kimenet első sorába azon napok K számát kell kiírni, amikor legalább a telepü-
            lések felében melegedés várható az előző naphoz képest! Ezt kövesse ezen napok sorszáma, nö-
            vekvő sorrendben.
                Példa

                Bemenet              Kimenet
                3 5                   2 2 5
                10 15 12 10 10
                11 11 11 11 20
                12 16 16 16 20

        3 5
10 15 12 10 10
11 11 11 11 20
12 16 16 16 20
        */

        // DEKLARACIO
        int N; // 1 <= N <= 1000
        int M; // 1 <= M <= 1000
        int i, j;
        List<int> K = new List<int>();
        List<int> ind = new List<int>();

        // BEOLVASAS
        string str = Console.ReadLine();
        N = Convert.ToInt32(str.Split(' ')[0]);
        M = Convert.ToInt32(str.Split(' ')[1]);

        int[,] Hi = new int[N, M];

        //Feltoltes

        for (i = 0; i < N; i++)
        {
            string[] rowValues = Console.ReadLine().Split(' ');
            for (j = 0; j < M; j++)
            {
                Hi[i, j] = int.Parse(rowValues[j]);
            }
        }

        //Feldolgozas

        for (j = 0; j < M - 1; j++)
        {
            int db = 0;
            for (i = 0; i < N; i++)
            {
                if (Hi[i, j] < Hi[i, j + 1])
                {
                    db++;
                }
            }
        }

        

        // KIIRATAS
        Console.Write("{0} ", K.Count);
        K.ForEach(i => Console.Write("{0} ", i));
    }
}
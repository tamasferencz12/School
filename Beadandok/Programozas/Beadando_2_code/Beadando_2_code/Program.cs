using System;

public class MyProgram {

    static void ifLastNegModification(int db, int N,int[] M, int[] y)
    {
        if (M[N] < 0)
        {
            M[N + 1] = 10000;
            y[db+1] = y[db] + 2;
        }
    }

    static int function(int e,  int[] y)
    {
        int felt;
        if (y[e+1] - y[e] != 1 )
        {
            felt = 1;
        }
        else
        {
            felt = 0;
        }

        return felt;
    }

    public static void Main(string[] args)
    {
        // Ferencz Tamás, G0820E, tamasferencz25@gmail.com

        /*
                Fagyos időszaknak nevezzük egymás utáni napok olyan tovább már egyik irányba sem bővíthető sorozatát, amikor a hőmérséklet folyamatosan 0 fok alatt volt.
            Az elmúlt N nap hőmérséklete alapján számold meg, hány fagyos időszak volt!
                Bemenet
            A standard bemenet első sorában a vizsgált napok száma (1N50), alat- ta soronként a napi mérések eredményei vannak (-100≤M≤100).
                Kimenet
            A standard kimenet egyetlen sorába egyetlen egész számot kell írni, a fagyos időszakok számát!
        */

        // DEKLARACIO
        int N; // 1 <= N <= 50
        int db = 0; // darabszam
        int dbv = 0; // darabszam vegleges
        int[] M; // -100 <= M <= 100
        int[] y;
        int[] z;

        // BEOLVASAS
        N = int.Parse(Console.ReadLine());

        M = new int[N+1+1];
        y = new int[N+2];
        z = new int[N+2];

        for (int i = 1; i <= N; i++)
        {
           M[i] = int.Parse(Console.ReadLine());
        }

        // FELDOLGOZAS

        // y tomb feltotese

        for (int i = 1; i <= N; i++)
        {
            if (M[i] < 0)
            {
                db++;
                y[db] = i;
            }
        }

        ifLastNegModification(db,N, M, y);

         // z tomb feltoltese

        for (int i = 1; i <= db; i++)
        {
            z[i - 1 + 1] = function(i, y);
        }

        for (int i = 1; i <= db; i++)
        {
            if (z[i] > 0)
            {
                dbv++;
            }
        }

        // KIIRATAS

        Console.WriteLine(dbv);
    }
}
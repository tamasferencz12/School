using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int index;
        bool jo;
        jo = false;
        int i=0;
        string[] kartyak = {"also", "felso", "kiraly", "asz", "hetes", "nyolcas", "kilences", "tizes"};
        int[] ertekek = {2, 3, 4, 11, 7, 8, 9, 10};


        Console.WriteLine("Adja meg a kartyajat: ");
        string kartya = Console.ReadLine();

        while(!jo)
        {
            Console.WriteLine("Adja meg a kartyajat: ");
            kartya = Console.ReadLine();
            i = 0;
            while(i<=8 && kartya != kartyak[i])
            {
                i++;
            }
            jo = (i <= 8);
        }
        Console.WriteLine("-------------------------------");

        /*for(int i = 1; i <= 9; i++)
        {
            if (kartya == kartyak[i])
            {
                index = i;
            }
        }
        */
    }

}

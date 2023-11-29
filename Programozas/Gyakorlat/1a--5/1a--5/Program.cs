using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int h, m, s,x, sec;

        sec = Convert.ToInt32(Console.ReadLine());
        h = sec / 3600;
        x = sec % 3600;
        m = x / 60;
        x = sec % (3600/60);
        s = x;

        Console.WriteLine($"{h}:{m}:{s}");

    }
}

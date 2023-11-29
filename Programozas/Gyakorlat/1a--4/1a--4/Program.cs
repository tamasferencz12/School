using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int h;
        int m;
        int s;
        int sec;

        sec = 0;
        h = (int)inputValue();
        m = (int)inputValue();
        s = (int)inputValue();
        if (0 <= h && m >= 0 && s >= 0 && h <= 23 && m < 60 && s < 60)
        {
            sec = h * 3600 + m * 60 + s;
            Console.WriteLine(sec);
        }
        else
        {
            Console.WriteLine("Hibas bemenet!");
        }
    }

    // .NET can only read single characters or entire lines from the
    // console. The following function safely reads a double value.
    private static double inputValue()
    {
        double result;
        while (!double.TryParse(Console.ReadLine(), out result)) ;
        return result;
    }
}

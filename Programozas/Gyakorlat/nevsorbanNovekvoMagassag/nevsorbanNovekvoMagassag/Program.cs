using System;

public class MyProgram
{
    public static void Main(string[] args)
    {
        int n;
        int j = 0;
        bool isItGood = true;
        n = int.Parse(Console.ReadLine());

        string[] name = new string[n];
        int[] height = new int[n];

        for (int i = 0; i < n; i++)
        {
            string str = Console.ReadLine();
            name[i] = str.Split(' ')[0];
            height[i] = Convert.ToInt32(str.Split(' ')[1]);
        }

        while (isItGood && j < n-1) { 
            if (height[j] <= height[j + 1])
            {
                isItGood = true;
            }else
            {
                isItGood = false;
            }
            j++;
        }

        if (isItGood)
        {
            Console.WriteLine("IGEN");
        }
        else
        {
            Console.WriteLine("NEM");
        }
    }
}

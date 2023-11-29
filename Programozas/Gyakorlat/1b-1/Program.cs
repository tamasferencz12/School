using System;

namespace HelloWorld
{
    class Program
    {
        private static int x;

        static void Main(string[] args)
        {
            int x = int.Parse(Console.ReadLine());

            if (x > 0)
            {
                Console.WriteLine("A szam: " + x);
            }
            else
            {
                Console.WriteLine("Hibas a beadott szam!");
            }
            
        }
    }
}
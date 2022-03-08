using System;
using System.Runtime.InteropServices;

namespace DotnetNativeInterprop
{
    public class Program
    {

        [DllImport("./libnative.so")]
        private static extern void Print();

        [DllImport("./libnative.so")]
        private static extern void MakeWindow();

        [DllImport("./libnative.so")]
        private static extern void CloseWindow();

        static void Main()
        {
            Console.WriteLine("Hello World!");
            Print();

            MakeWindow();

            Thread.Sleep(5000);

            CloseWindow();
        }
    }
}

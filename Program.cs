using System;
using System.Runtime.InteropServices;

namespace DotnetNativeInterprop
{
    public class Program
    {

        static void Main()
        {
            var LibNative = LibNativeProvider.Get();

            Console.WriteLine("Hello World!");
            LibNative.Print();

            LibNative.MakeWindow();

            Thread.Sleep(5000);

            LibNative.CloseWindow();
        }
    }
}

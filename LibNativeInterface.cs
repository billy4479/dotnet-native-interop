using System.Runtime.InteropServices;


namespace DotnetNativeInterprop
{

    // Thanks to https://stackoverflow.com/a/52297584

    interface ILibNative
    {
        void Print();
        void MakeWindow();
        void CloseWindow();
    }

    class WindowsLibNative : ILibNative
    {
        [DllImport("./native.dll", EntryPoint = "Print")]
        private static extern void CallPrint();

        [DllImport("./native.dll", EntryPoint = "MakeWindow")]
        private static extern void CallMakeWindow();

        [DllImport("./native.dll", EntryPoint = "CloseWindow")]
        private static extern void CallCloseWindow();


        public void Print()
        {
            CallPrint();
        }

        public void MakeWindow()
        {
            CallMakeWindow();
        }

        public void CloseWindow()
        {
            CallCloseWindow();
        }
    }

    class LinuxLibNative : ILibNative
    {
        [DllImport("./libnative.so", EntryPoint = "Print")]
        private static extern void CallPrint();

        [DllImport("./libnative.so", EntryPoint = "MakeWindow")]
        private static extern void CallMakeWindow();

        [DllImport("./libnative.so", EntryPoint = "CloseWindow")]
        private static extern void CallCloseWindow();


        public void Print()
        {
            CallPrint();
        }

        public void MakeWindow()
        {
            CallMakeWindow();
        }

        public void CloseWindow()
        {
            CallCloseWindow();
        }
    }


    static class LibNativeProvider
    {
        public static ILibNative Get()
        {
            return RuntimeInformation.IsOSPlatform(OSPlatform.Windows) ? new WindowsLibNative() : new LinuxLibNative();
        }
    }
}
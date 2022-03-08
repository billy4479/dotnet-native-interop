using System.Runtime.InteropServices;

namespace DotnetNativeInterop
{
    // Thanks to https://stackoverflow.com/a/52297584

    interface ILibNative
    {
        IntPtr MakeWindow();
        void CloseWindow(IntPtr ptr);
        void Clear(IntPtr ptr, byte r, byte g, byte b);
    }

    class WindowsLibNative : ILibNative
    {
        [DllImport("./native.dll", EntryPoint = "MakeWindow")]
        private static extern IntPtr CallMakeWindow();

        [DllImport("./native.dll", EntryPoint = "CloseWindow")]
        private static extern void CallCloseWindow(IntPtr ptr);

        [DllImport("./native.dll", EntryPoint = "Clear")]
        private static extern void CallClear(IntPtr ptr, byte r, byte g, byte b);

        public IntPtr MakeWindow()
        {
            return CallMakeWindow();
        }

        public void CloseWindow(IntPtr ptr)
        {
            CallCloseWindow(ptr);
        }

        public void Clear(IntPtr ptr, byte r, byte g, byte b)
        {
            CallClear(ptr, r, g, b);
        }
    }

    class LinuxLibNative : ILibNative
    {
        [DllImport("./libnative.so", EntryPoint = "MakeWindow")]
        private static extern IntPtr CallMakeWindow();

        [DllImport("./libnative.so", EntryPoint = "CloseWindow")]
        private static extern void CallCloseWindow(IntPtr ptr);

        [DllImport("./libnative.so", EntryPoint = "Clear")]
        private static extern void CallClear(IntPtr ptr, byte r, byte g, byte b);

        public IntPtr MakeWindow()
        {
            return CallMakeWindow();
        }

        public void CloseWindow(IntPtr ptr)
        {
            CallCloseWindow(ptr);
        }

        public void Clear(IntPtr ptr, byte r, byte g, byte b)
        {
            CallClear(ptr, r, g, b);
        }
    }

    static class LibNativeProvider
    {
        private static ILibNative? Instance = null;
        public static ILibNative Get()
        {
            if (Instance == null)
                Instance = RuntimeInformation.IsOSPlatform(OSPlatform.Windows) ? new WindowsLibNative() : new LinuxLibNative();

            return Instance;
        }
    }
}
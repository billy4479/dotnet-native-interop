namespace DotnetNativeInterprop
{
    internal class MyWindow : IDisposable
    {
        IntPtr ptr;

        public MyWindow()
        {
            ptr = LibNativeProvider.Get().MakeWindow();
        }

        public void Clear(byte r, byte g, byte b)
        {
            LibNativeProvider.Get().Clear(ptr, r, g, b);
        }

        public void Dispose()
        {
            LibNativeProvider.Get().CloseWindow(ptr);
        }
    }
}
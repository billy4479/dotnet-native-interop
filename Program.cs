
namespace DotnetNativeInterprop
{
    public class Program
    {
        static void Main()
        {
            using var window = new MyWindow();
            Thread.Sleep(1000);
            window.Clear(0, 0xff, 0);

            Thread.Sleep(1000);
            window.Clear(0, 0, 0xff);

            Thread.Sleep(1000);
            window.Clear(0xff, 0, 0);

            Thread.Sleep(1000);
        }
    }
}

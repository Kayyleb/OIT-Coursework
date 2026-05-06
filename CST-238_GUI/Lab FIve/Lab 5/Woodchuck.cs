using Microsoft.Maui.Controls;
using Microsoft.Maui.Layouts;

namespace Lab_5
{
    public class Woodchuck : Image
    {
        private double maxX;
        private double maxY;
        private AbsoluteLayout layout;
        private Random random = new Random();

        public Woodchuck(AbsoluteLayout layout)
        {
            this.layout = layout;

            Source = "woodchuck.png";
            WidthRequest = 200;
            HeightRequest = 100;
            Aspect = Aspect.AspectFit;
            ZIndex = 50;

            // Hover over woodchuck to make it disappear
            var pointerGesture = new PointerGestureRecognizer();
            pointerGesture.PointerEntered += (s, e) => IsVisible = false;
            GestureRecognizers.Add(pointerGesture);

            Loaded += StartAnimation;
        }

        private async void StartAnimation(object sender, EventArgs e)
        {
            maxX = layout.Width;
            maxY = layout.Height;

            AbsoluteLayout.SetLayoutBounds(this, new Rect(0, 0, 200, 100));
            AbsoluteLayout.SetLayoutFlags(this, AbsoluteLayoutFlags.None);

            await move();
        }

        private async Task move()
        {
            while (true)
            {
                await Task.Run(() => {
                    System.Threading.Thread.Sleep(2);
                });

                double x = random.NextDouble() * (layout.Width - 200); // clamp to layout bounds 
                double y = random.NextDouble() * (layout.Height - 100); // so woodchuck doesn't go out of screen
                uint duration = (uint)random.Next(800, 2000);

                await this.TranslateToAsync(x, y, duration);
            }
        }
    }
}